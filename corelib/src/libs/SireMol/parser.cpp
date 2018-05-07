/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2018  Christopher Woods
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 2 of the License, or
  *  (at your option) any later version.
  *
  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  *
  *  For full details of the license please see the COPYING file
  *  that should have come with this distribution.
  *
  *  You can contact the authors via the developer's mailing list
  *  at http://siremol.org
  *
\*********************************************/

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>

#include "parser.h"

#include "tostring.h"

#include <QDebug>

using namespace SireMol;
using namespace SireMol::parser;
using namespace SireBase;

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

/** Internal class providing the SelectEngine for objects 
    based on their IDs (names, numbers, indicies etc.) 
    
    @author Christopher Woods
*/
class IDEngine : public SelectEngine
{
public:
    enum Obj { ATOM = 1,
               CUTGROUP = 2,
               RESIDUE = 3,
               CHAIN = 4,
               SEGMENT = 5,
               MOLECULE = 6 };
    
    enum Typ { NAME = 1,
               NAME_REGEXP = 2,
               NUMBER = 3,
               NUMBER_LIST = 4,
               INDEX = 5,
               INDEX_LIST = 6 };

    IDEngine() : SelectEngine()
    {}
    
    IDEngine(const std::wstring &nam)
    {
        idnam = QString::fromStdWString(nam);
    }
    
    ~IDEngine()
    {}
    
    Obj obj;
    Typ typ;
    
    QString idnam;
    qint64 idnum;
    QList<qint64> idnums;
};

template<typename Iterator>
struct idengine_parser : qi::grammar<Iterator, IDEngine(), ascii::space_type>
{
    idengine_parser() : idengine_parser::base_type(start)
    {
        using qi::int_;
        using qi::_val;
        using qi::eps;
        using qi::lit;
        using qi::double_;
        using qi::_1;
        using qi::lexeme;
        using ascii::char_;

        string_or_regexp %= lexeme[+char_];

        start %=
                lit("resname")
                >> string_or_regexp
            ;
    }
    
    qi::rule<Iterator, IDEngine(), ascii::space_type> start;
    qi::rule<Iterator, std::wstring(), ascii::space_type> string_or_regexp;
};

namespace parser
{
    namespace qi = boost::spirit::qi;
    using boost::spirit::qi::int_;
    using boost::spirit::ascii::space;
    
    void print(const int &i)
    {
        qDebug() << "FOUND" << i;
    }
    
    /** Internal function that uses boost::spirit to do the parsing */
    boost::shared_ptr<SelectEngine> parse_select(const QString &str)
    {
        //get a standard wstring from the QString
        const auto s = str.toStdWString();
        
        IDEngine eng;
        idengine_parser<std::wstring::const_iterator> g;
        
        bool r = phrase_parse(s.begin(), s.end(), g, space, eng);

        if (r)
        {
            qDebug() << "PARSING SUCCESSFUL";
            qDebug() << eng.idnam;
        }
        else
        {
            qDebug() << "PARSING FAILED!";
        }
        
        return boost::shared_ptr<SelectEngine>(new IDEngine(eng));
    }
}

namespace SireMol
{
    /** Internal function used to parse the passed string and convert
        it into a set of Select objects */
    boost::shared_ptr<SelectEngine> parse( const QString &str )
    {
        qDebug() << "Parsing" << str;
        return ::parser::parse_select(str);
    }
}
