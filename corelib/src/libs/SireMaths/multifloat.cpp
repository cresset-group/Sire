/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2013  Christopher Woods
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

#include "multifloat.h"
#include "multidouble.h"
#include "multiuint.h"
#include "multiint.h"

#include "SireBase/unittest.h"

#include <QStringList>

#include "SireError/errors.h"

#include <QDebug>

using namespace SireMaths;

#ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
    static inline bool isAligned64(const void *pointer)
    {
     	return (quintptr)pointer % size_t(64) == 0;
    }

    static void assertAligned64(const void *pointer, QString place)
    {
     	if (not isAligned64(pointer))
            throw SireError::program_bug( QObject::tr(
                    "An unaligned MultiFloat has been created! %1")
                        .arg((quintptr)pointer % size_t(64)), place );
    }
#endif

#ifdef MULTIFLOAT_AVX_IS_AVAILABLE

    #if defined(__clang__)
        //the new clang on OS X breaks compilation of AVX functions
        #define AVX_MATHFUNC_BROKEN_INTO 1
        #define AVX_MATHFUNC_BROKEN_LOG 1
        #define AVX_MATHFUNC_BROKEN_EXP 1
    #endif

    #ifdef Q_OS_WIN
      //don't use AVX math functions yet on windows
      #define AVX_MATHFUNC_BROKEN_INTO 1
      #define AVX_MATHFUNC_BROKEN_LOG 1
      #define AVX_MATHFUNC_BROKEN_EXP 1
      #undef HAVE_AVX_MATHFUN
    #else
      #include "ThirdParty/avx_mathfun.h" // CONDITIONAL_INCLUDE
      #define HAVE_AVX_MATHFUN 1
    #endif  

    static inline bool isAligned32(const void *pointer)
    {
        return (quintptr)pointer % size_t(32) == 0;
    }

    static void assertAligned32(const void *pointer, QString place)
    {
        if (not isAligned32(pointer))
            throw SireError::program_bug( QObject::tr(
                    "An unaligned MultiFloat has been created! %1")
                        .arg((quintptr)pointer % size_t(32)), place );
    }

    namespace SireMaths
    {
        MultiFloat cos(const MultiFloat &val)
        {
            #ifdef HAVE_AVX_MATHFUN
              return MultiFloat( cos256_ps(val.v.x) );
            #else
              MultiFloat ret;
              for (int i=0; i<MultiFloat::count(); ++i)
              {
                  ret.quickSet(i, std::cos(val.at(i)));
              }

              return ret;
            #endif
        }
        
        MultiFloat sin(const MultiFloat &val)
        {
            #ifdef HAVE_AVX_MATHFUNC
              return MultiFloat( sin256_ps(val.v.x) );
            #else
              MultiFloat ret;
              for (int i=0; i<MultiFloat::count(); ++i)
              {
                  ret.quickSet(i, std::sin(val.at(i)));
              }

              return ret;
            #endif
        }
        
        MultiFloat exp(const MultiFloat &val)
        {
            #ifndef AVX_MATHFUNC_BROKEN_EXP
                return MultiFloat( exp256_ps(val.v.x) );
            #else
                MultiFloat ret;
                for (int i=0; i<MultiFloat::count(); ++i)
                {
                    ret.quickSet(i, std::exp(val.at(i)));
                }

                return ret;
            #endif
        }
        
        MultiFloat log(const MultiFloat &val)
        {
            #ifndef AVX_MATHFUNC_BROKEN_LOG
                return MultiFloat( log256_ps(val.v.x) );
            #else
                MultiFloat ret;
                for (int i=0; i<MultiFloat::count(); ++i)
                {
                    ret.quickSet(i, std::log(val.at(i)));
                }

                return ret;
            #endif
        }
        
        void sincos(const MultiFloat &val, MultiFloat &sval, MultiFloat &cval)
        {
            #ifdef HAVE_AVX_MATHFUN
              sincos256_ps(val.v.x, &(sval.v.x), &(cval.v.x));
            #else
              MultiFloat sret, cret;
              for (int i=0; i<MultiFloat::count(); ++i)
              {
                  sret.quickSet(i, std::sin(val.at(i)));
                  cret.quickSet(i, std::cos(val.at(i)));
              }
            #endif        
        }
    }

#else
#ifdef MULTIFLOAT_SSE_IS_AVAILABLE
    #include "ThirdParty/sse_mathfun.h" // CONDITIONAL_INCLUDE

    static inline bool isAligned16(const void *pointer)
    {
        return (quintptr)pointer % size_t(16) == 0;
    }

    static void assertAligned16(const void *pointer, QString place)
    {
        if (not isAligned16(pointer))
            throw SireError::program_bug( QObject::tr(
                    "An unaligned MultiFloat has been created! %1")
                        .arg((quintptr)pointer % size_t(16)), place );
    }

    namespace SireMaths
    {
        MultiFloat cos(const MultiFloat &val)
        {
            return MultiFloat( cos_ps(val.v.x) );
        }
        
        MultiFloat sin(const MultiFloat &val)
        {
            return MultiFloat( sin_ps(val.v.x) );
        }
        
        MultiFloat exp(const MultiFloat &val)
        {
            return MultiFloat( exp_ps(val.v.x) );
        }
        
        MultiFloat log(const MultiFloat &val)
        {
            return MultiFloat( log_ps(val.v.x) );
        }
        
        void sincos(const MultiFloat &val, MultiFloat &sval, MultiFloat &cval)
        {
            sincos_ps(val.v.x, &(sval.v.x), &(cval.v.x));
        }
    }

#else
    #include "sincos.h"

    static inline bool isAligned32(const void *pointer)
    {
        return (quintptr)pointer % size_t(32) == 0;
    }

    static void assertAligned32(const void *pointer, QString place)
    {
        if (not isAligned32(pointer))
            throw SireError::program_bug( QObject::tr(
                    "An unaligned MultiFloat has been created! %1")
                        .arg((quintptr)pointer % size_t(32)), place );
    }

    namespace SireMaths
    {
        MultiFloat cos(const MultiFloat &val)
        {
            MultiFloat ret;
            
            for (int i=0; i<MultiFloat::count(); ++i)
            {
                ret.v.a[i] = std::cos(val.v.a[i]);
            }
        
            return ret;
        }
        
        MultiFloat sin(const MultiFloat &val)
        {
            MultiFloat ret;
            
            for (int i=0; i<MultiFloat::count(); ++i)
            {
                ret.v.a[i] = std::sin(val.v.a[i]);
            }
        
            return ret;
        }
        
        MultiFloat exp(const MultiFloat &val)
        {
            MultiFloat ret;
            
            for (int i=0; i<MultiFloat::count(); ++i)
            {
                ret.v.a[i] = std::exp(val.v.a[i]);
            }
        
            return ret;
        }
        
        MultiFloat log(const MultiFloat &val)
        {
            MultiFloat ret;
            
            for (int i=0; i<MultiFloat::count(); ++i)
            {
                ret.v.a[i] = std::log(val.v.a[i]);
            }
        
            return ret;
        }
        
        void sincos(const MultiFloat &val, MultiFloat &sval, MultiFloat &cval)
        {
            for (int i=0; i<MultiFloat::count(); ++i)
            {
                SireMaths::sincos(val.v.a[i], &(sval.v.a[i]), &(cval.v.a[i]));
            }
        }
    }

#endif
#endif

void MultiFloat::assertAligned(const void *ptr, size_t size)
{
    if ( (quintptr)ptr % size != 0 )
        throw SireError::program_bug( QObject::tr(
                "An unaligned MultiFloat has been created! %1, %2, %3")
                    .arg((quintptr)ptr)
                    .arg((quintptr)ptr % size)
                    .arg(size), CODELOC );
}

/** Construct from the passed array, taking the values of each element
    of the vector from the index in the associated MultiInt, e.g.
    
    MultiFloat[i] = array[ MultiInt[i] ]
*/
MultiFloat::MultiFloat(const float *array, const MultiInt &idxs)
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        v.a[i] = array[ idxs.v.a[i] ];
    }
}

/** Construct from the passed array. If size is greater than MultiFloat::size()
    then an error will be raised. If size is less than MultiFloat::size() then
    this float will be padded with zeroes */
MultiFloat::MultiFloat(const float *array, int size)
{
    assertAligned();

    if (size > MULTIFLOAT_SIZE)
        throw SireError::unsupported( QObject::tr(
                "Cannot fit an array of size %1 in this MultiFloat, as it is only "
                "capable of holding %2 values...").arg(size).arg(MULTIFLOAT_SIZE), CODELOC );

    if (size <= 0)
    {
        #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
            v.x = _mm512_set1_ps(0);
        #else
        #ifdef MULTIFLOAT_AVX_IS_AVAILABLE
            v.x = _mm256_set1_ps(0);
        #else
        #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
            v.x = _mm_set1_ps(0);
        #else
            for (int i=0; i<MULTIFLOAT_SIZE; ++i)
            {
                v.a[i] = 0;
            }
        #endif
        #endif
        #endif
    }
    else if (size == MULTIFLOAT_SIZE)
    {
        #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
            v.x = _mm512_set_ps(array[15], array[14], array[13], array[12],
                                array[11], array[10], array[9], array[8],
                                array[7], array[6], array[5], array[4],
                                array[3], array[2], array[1], array[0]);
        #else
        #ifdef MULTIFLOAT_AVX_IS_AVAILABLE
            v.x = _mm256_set_ps(array[7], array[6], array[5], array[4],
                                array[3], array[2], array[1], array[0]);
        #else
        #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
            //note that SSE packs things the 'wrong' way around
            v.x = _mm_set_ps(array[3], array[2], array[1], array[0]);
        #else
            for (int i=0; i<MULTIFLOAT_SIZE; ++i)
            {
                v.a[i] = array[i];
            }
        #endif
        #endif
        #endif
    }
    else
    {
        float tmp[MULTIFLOAT_SIZE];
        
        for (int i=0; i<size; ++i)
        {
            tmp[i] = array[i];
        }
        
        for (int i=size; i<MULTIFLOAT_SIZE; ++i)
        {
            tmp[i] = 0;
        }
        
        #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
            v.x = _mm512_set_ps(tmp[15], tmp[14], tmp[13], tmp[12],
                                tmp[11], tmp[10], tmp[9], tmp[8],
                                tmp[7], tmp[6], tmp[5], tmp[4],
                                tmp[3], tmp[2], tmp[1], tmp[0]);
        #else
        #ifdef MULTIFLOAT_AVX_IS_AVAILABLE
            v.x = _mm256_set_ps(tmp[7], tmp[6], tmp[5], tmp[4],
                                tmp[3], tmp[2], tmp[1], tmp[0]);
        #else
        #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
            //note that sse packs things the 'wrong' way around
            v.x = _mm_set_ps(tmp[3], tmp[2], tmp[1], tmp[0]);
        #else
            for (int i=0; i<MULTIFLOAT_SIZE; ++i)
            {
                v.a[i] = tmp[i];
            }
        #endif
        #endif
        #endif
    }
}

/** Construct from the passed array - this must be the same size as the vector */
MultiFloat::MultiFloat(const QVector<float> &array)
{
    assertAligned();
    this->operator=( MultiFloat(array.constData(), array.size()) );
}

/** Construct from the passed array - this must be the same size as the vector */
MultiFloat::MultiFloat(const QVector<double> &array)
{
    assertAligned();

    QVector<float> farray;
    farray.reserve(array.count());
    
    for (int i=0; i<array.count(); ++i)
    {
        farray.append(array.constData()[i]);
    }

    this->operator=( MultiFloat(farray) );
}

/** Construct from a MultiInt */
MultiFloat::MultiFloat(const MultiInt &other)
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        v.a[i] = other.v.a[i];
    }
}

/** Copy assignment from a MultiInt */
MultiFloat& MultiFloat::operator=(const MultiInt &other)
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        v.a[i] = other.v.a[i];
    }
    
    return *this;
}

/** Return whether or not this MultiFloat is correctly aligned. If it is not,
    then any SSE operations will fail */
bool MultiFloat::isAligned() const
{
    #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
        return isAligned64(this);
    #else
    #ifdef MULTIFLOAT_AVX_IS_AVAILABLE
        return isAligned32(this);
    #else
    #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
        return isAligned16(this);
    #else
        return true;
    #endif
    #endif
    #endif
}

QVector<MultiFloat> MultiFloat::fromArray(const double *array, int size)
{
    if (size == 0)
        return QVector<MultiFloat>();

    #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
        float _ALIGNED(64) tmp[MULTIFLOAT_SIZE];
    #else
    #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
        float _ALIGNED(16) tmp[MULTIFLOAT_SIZE];
    #else
        float _ALIGNED(32) tmp[MULTIFLOAT_SIZE];
    #endif
    #endif    

    int nvecs = size / MULTIFLOAT_SIZE;
    int nremain = size % MULTIFLOAT_SIZE;

    QVector<MultiFloat> marray(nvecs + ( (nremain > 0) ? 1 : 0 ));
    MultiFloat *a = marray.data();
    
    int idx = 0;
    
    for (int i=0; i<nvecs; ++i)
    {
        for (int j=0; j<MULTIFLOAT_SIZE; ++j)
        {
            tmp[j] = array[idx];
            ++idx;
        }
    
        a[i] = MultiFloat((float*)(&tmp), MULTIFLOAT_SIZE);
    }
    
    if (nremain > 0)
    {
        for (int j=0; j<nremain; ++j)
        {
            tmp[j] = array[idx];
            ++idx;
        }
        
        a[marray.count()-1] = MultiFloat((float*)(&tmp), nremain);
    }
    
    #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
        assertAligned64(marray.constData(), CODELOC);
    #else
    #ifdef MULTIFLOAT_AVX_IS_AVAILABLE
        assertAligned32(marray.constData(), CODELOC);
    #else
    #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
        assertAligned16(marray.constData(), CODELOC);
    #else
        assertAligned32(marray.constData(), CODELOC);
    #endif
    #endif
    #endif

    return marray;
}

/** Create an array of MultiFloats from the passed array of doubles. This
    will pad the end of the array with zeroes if necessary */
QVector<MultiFloat> MultiFloat::fromArray(const QVector<double> &array)
{
    return MultiFloat::fromArray(array.constData(), array.count());
}

QVector<MultiFloat> MultiFloat::fromArray(const float *array, int size)
{
    if (size == 0)
        return QVector<MultiFloat>();
    
    int nvecs = size / MULTIFLOAT_SIZE;
    int nremain = size % MULTIFLOAT_SIZE;
    
    QVector<MultiFloat> marray(nvecs + ( (nremain > 0) ? 1 : 0 ));
    MultiFloat *ma = marray.data();
    
    int idx = 0;
    
    #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
        if (isAligned16(array))
        {
            for (int i=0; i<nvecs; ++i)
            {
                ma[i] = MultiFloat(array+idx, MULTIFLOAT_SIZE);
                idx += MULTIFLOAT_SIZE;
            }
    
            if (nremain > 0)
            {
                ma[marray.count()-1] = MultiFloat(array+idx, nremain);
            }
        }
        else
        {
            float _ALIGNED(16) tmp[MULTIFLOAT_SIZE];

            for (int i=0; i<nvecs; ++i)
            {
                for (int j=0; j<MULTIFLOAT_SIZE; ++j)
                {
                    tmp[j] = array[idx];
                    ++idx;
                }
            
                ma[i] = MultiFloat((float*)(&tmp), MULTIFLOAT_SIZE);
            }
            
            if (nremain > 0)
            {
                for (int j=0; j<nremain; ++j)
                {
                    tmp[j] = array[idx];
                    ++idx;
                }
                
                ma[marray.count()-1] = MultiFloat((float*)(&tmp), nremain);
            }
        }
    #else
        if (isAligned32(array))
        {
            for (int i=0; i<nvecs; ++i)
            {
                ma[i] = MultiFloat(array+idx, MULTIFLOAT_SIZE);
                idx += MULTIFLOAT_SIZE;
            }
    
            if (nremain > 0)
            {
                ma[marray.count()-1] = MultiFloat(array+idx, nremain);
            }
        }
        else
        {
            float _ALIGNED(32) tmp[MULTIFLOAT_SIZE];

            for (int i=0; i<nvecs; ++i)
            {
                for (int j=0; j<MULTIFLOAT_SIZE; ++j)
                {
                    tmp[j] = array[idx];
                    ++idx;
                }
            
                ma[i] = MultiFloat((float*)(&tmp), MULTIFLOAT_SIZE);
            }
            
            if (nremain > 0)
            {
                for (int j=0; j<nremain; ++j)
                {
                    tmp[j] = array[idx];
                    ++idx;
                }
                
                ma[marray.count()-1] = MultiFloat((float*)(&tmp), nremain);
            }
        }
    #endif

    #ifdef MULTIFLOAT_AVX512F_IS_AVAILABLE
        assertAligned64(marray.constData(), CODELOC);
    #else
    #ifdef MULTIFLOAT_AVX_IS_AVAILABLE
        assertAligned32(marray.constData(), CODELOC);
    #else
    #ifdef MULTIFLOAT_SSE_IS_AVAILABLE
        assertAligned16(marray.constData(), CODELOC);
    #else
        assertAligned32(marray.constData(), CODELOC);
    #endif
    #endif
    #endif    

    return marray;
}

/** Create an array of MultiFloats from the passed array of floats. This will
    pad the end of the array with zeroes if necessary */
QVector<MultiFloat> MultiFloat::fromArray(const QVector<float> &array)
{
    return MultiFloat::fromArray(array.constData(), array.count());
}

/** Return the passed MultiFloat converted back into a normal array */
QVector<float> MultiFloat::toArray(const QVector<MultiFloat> &array)
{
    if (array.isEmpty())
        return QVector<float>();
    
    QVector<float> ret;
    ret.reserve( array.count() * MULTIFLOAT_SIZE );
    
    for (int i=0; i<array.count(); ++i)
    {
        const MultiFloat &f = array.constData()[i];
        
        for (int j=0; j<MULTIFLOAT_SIZE; ++j)
        {
            ret.append(f[j]);
        }
    }
    
    return ret;
}

/** Return the passed MultiFloat converted back into a normal array of doubles */
QVector<double> MultiFloat::toDoubleArray(const QVector<MultiFloat> &array)
{
    if (array.isEmpty())
        return QVector<double>();
    
    QVector<double> ret;
    ret.reserve( array.count() * MULTIFLOAT_SIZE );
    
    for (int i=0; i<array.count(); ++i)
    {
        const MultiFloat &f = array.constData()[i];
        
        for (int j=0; j<MULTIFLOAT_SIZE; ++j)
        {
            ret.append(f[j]);
        }
    }
    
    return ret;
}

/** Comparison operator - only returns true if all elements are equal */
bool MultiFloat::operator==(const MultiFloat &other) const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        if (v.a[i] != other.v.a[i])
            return false;
    }

    return true;
}

/** Comparison operator - only returns true if all elements are not equal */
bool MultiFloat::operator!=(const MultiFloat &other) const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        if (v.a[i] == other.v.a[i])
            return false;
    }

    return true;
}

/** Return whether all of the elements of this MultiFloat are 
    equal to 0x00000000 (e.g. every bit in the entire vector is 0) */
bool MultiFloat::isBinaryZero() const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        static const quint32 bin_zero = 0x00000000;
    
        if (*(reinterpret_cast<const quint32*>(&(v.a[i]))) != bin_zero)
            return false;
    }
    
    return true;
}

/** Return whether all of the elements of this MultiFloat are
    not equal to 0x00000000 (e.g. at least one bit in the entire vector is 1) */
bool MultiFloat::isNotBinaryZero() const
{
    return not isBinaryZero();
}

/** Return whether or not at least one of the elements of this vector
    is binary zero (the float is equal to 0x00000000) */
bool MultiFloat::hasBinaryZero() const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        static const quint32 bin_zero = 0x00000000;
    
        if (*(reinterpret_cast<const quint32*>(&(v.a[i]))) == bin_zero)
            return true;
    }
    
    return false;
}

/** Return whether all of the elements of this MultiFloat are 
    equal to 0xFFFFFFFF (e.g. every bit in the entire vector is 1) */
bool MultiFloat::isBinaryOne() const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        static const quint32 bin_one = 0xFFFFFFFF;
    
        if (*(reinterpret_cast<const quint32*>(&(v.a[i]))) != bin_one)
            return false;
    }
    
    return true;
}

/** Return whether all of the elements of this MultiFloat are
    not equal to 0xFFFFFFFF (e.g. at least one bit in the entire vector is 0) */
bool MultiFloat::isNotBinaryOne() const
{
    return not isBinaryOne();
}

/** Return whether or not at least one of the elements of this vector
    is binary one (the float is equal to 0xFFFFFFFF) */
bool MultiFloat::hasBinaryOne() const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        static const quint32 bin_one = 0xFFFFFFFF;
    
        if (*(reinterpret_cast<const quint32*>(&(v.a[i]))) == bin_one)
            return true;
    }
    
    return false;
}

/** Comparison operator - only returns true if all elements are less */
bool MultiFloat::operator<(const MultiFloat &other) const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        if (v.a[i] >= other.v.a[i])
            return false;
    }

    return true;
}

/** Comparison operator - only returns true if all elements are greater */
bool MultiFloat::operator>(const MultiFloat &other) const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        if (v.a[i] <= other.v.a[i])
            return false;
    }

    return true;
}

/** Comparison operator - only returns true if all elements are less or equal */
bool MultiFloat::operator<=(const MultiFloat &other) const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        if (v.a[i] > other.v.a[i])
            return false;
    }

    return true;
}

/** Comparison operator - only returns true if all elements are greater or equal */
bool MultiFloat::operator>=(const MultiFloat &other) const
{
    for (int i=0; i<MULTIFLOAT_SIZE; ++i)
    {
        if (v.a[i] < other.v.a[i])
            return false;
    }

    return true;
}

/** Set the ith value of the multifloat to 'value' */
void MultiFloat::set(int i, float value)
{
    if (i < 0)
        i = MULTIFLOAT_SIZE + i;
    
    if (i < 0 or i >= MULTIFLOAT_SIZE)
    {
        throw SireError::invalid_index( QObject::tr(
                "Cannot access element %1 of MultiFloat (holds only %2 values)")
                    .arg(i).arg(MULTIFLOAT_SIZE), CODELOC );
    }

    v.a[i] = value;
}

/** Return the ith value in the multifloat */
float MultiFloat::get(int i) const
{
    if (i < 0)
        i = MULTIFLOAT_SIZE + i;
    
    if (i < 0 or i >= MULTIFLOAT_SIZE)
    {
        throw SireError::invalid_index( QObject::tr(
                "Cannot access element %1 of MultiFloat (holds only %2 values)")
                    .arg(i).arg(MULTIFLOAT_SIZE), CODELOC );
    }
    
    return v.a[i];
}

float MultiFloat::at(int i) const
{
    return this->get(i);
}

float MultiFloat::getitem(int i) const
{
    return this->get(i);
}

const char* MultiFloat::what() const
{
    return MultiFloat::typeName();
}

const char* MultiFloat::typeName()
{
    return "SireMaths::MultiFloat";
}

/** Return the maximum value in the vector */
float MultiFloat::max() const
{
    float m = v.a[0];
    
    for (int i=1; i<MultiFloat::count(); ++i)
    {
        m = qMax(m, v.a[i]);
    }
    
    return m;
}

/** Return the minimum value in the vector */
float MultiFloat::min() const
{
    float m = v.a[0];
    
    for (int i=1; i<MultiFloat::count(); ++i)
    {
        m = qMin(m, v.a[i]);
    }
    
    return m;
}

QString MultiFloat::toString() const
{
    QStringList vals;
    
    for (int i=0; i<this->count(); ++i)
    {
        vals.append( QString::number(v.a[i]) );
    }
    
    return QObject::tr("{ %1 }").arg(vals.join(", "));
}

QString MultiFloat::toBinaryString() const
{
    QStringList vals;
    
    for (int i=0; i<this->count(); ++i)
    {
        const unsigned char *c = reinterpret_cast<const unsigned char*>(&(v.a[i]));
        
        QString val("0x");
        
        for (unsigned int j=0; j<sizeof(float); ++j)
        {
            val.append( QString("%1").arg((unsigned short)(c[j]), 2, 16, QChar('0')) );
        }
        
        vals.append(val);
    }
    
    return QObject::tr("{ %1 }").arg(vals.join(", "));
}

/** Swap the values of the value at index idx0 in 'f0' with the value at index 'idx' in 'f1' */
void MultiFloat::swap(MultiFloat &f0, int idx0, MultiFloat &f1, int idx1)
{
    float tmp = f0.v.a[idx0];
    f0.v.a[idx0] = f1.v.a[idx1];
    f1.v.a[idx1] = tmp;
}

// some unit tests for MultiFloat

using SireBase::assert_equal;

/** test multifloat assignment and basic math */
void test_assign_multifloat(bool verbose)
{
    MultiFloat f;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        f.set(i, i+1);
    }

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        assert_equal( f[i], i+1.f, CODELOC );
    }

    f += 1.0;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        assert_equal( f[i], i+2.f, CODELOC );
    }

    f *= 2;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        assert_equal( f[i], 2.f * (i+2.f), CODELOC );
    }

    f /= 1.5;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        assert_equal( f[i], (2.f * (i+2.f))/1.5f, CODELOC );
    }

    f -= 1.7;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        assert_equal( f[i], ((2.f * (i+2.f))/1.5f) - 1.7f, CODELOC );
    }
}

SIRE_UNITTEST(test_assign_multifloat)

/** test more complex stuff */
void test_multifloat_math(bool verbose)
{
    MultiFloat f;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        f.set(i, -(i+1));
    }

    //this should create the positive values
    f &= MULTIFLOAT_POS_MASK;

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        assert_equal<float>( f[i], i+1, CODELOC );
    }

    // compare to less than 3
    MultiFloat three(3.0);

    f &= f.compareLess(3.0);

    for (int i=0; i<MultiFloat::count(); ++i)
    {
        if (i+1 >= 3.0)
            assert_equal<float>( f[i], 0.0, CODELOC );
        else
            assert_equal<float>( f[i], i+1, CODELOC );
    }
}

SIRE_UNITTEST(test_multifloat_math)
