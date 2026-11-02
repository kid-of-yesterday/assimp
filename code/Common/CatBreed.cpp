/*
---------------------------------------------------------------------------
Open Asset Import Library (assimp)
---------------------------------------------------------------------------

Copyright (c) 2006-2026, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the following
conditions are met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the
following disclaimer in the documentation and/or other
materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
contributors may be used to endorse or promote products
derived from this software without specific prior
written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

/** @file  CatBreed.cpp
 *  @brief Implementation of the CatBreed data class.
 */
#include "CatBreed.h"

#include <sstream>
#include <stdexcept>
#include <utility>

namespace Assimp {

// ------------------------------------------------------------------------------------------------
CatBreed::CatBreed(std::string name, std::string originCountry, CoatLength coatLength,
        float minWeightKg, float maxWeightKg,
        unsigned int minLifespan, unsigned int maxLifespan) :
        mName(std::move(name)),
        mOriginCountry(std::move(originCountry)),
        mCoatLength(coatLength),
        mMinWeightKg(minWeightKg),
        mMaxWeightKg(maxWeightKg),
        mMinLifespan(minLifespan),
        mMaxLifespan(maxLifespan) {
    if (mMinWeightKg < 0.0f || mMinWeightKg > mMaxWeightKg) {
        throw std::invalid_argument("CatBreed: invalid weight range.");
    }
    if (mMinLifespan > mMaxLifespan) {
        throw std::invalid_argument("CatBreed: invalid lifespan range.");
    }
}

// ------------------------------------------------------------------------------------------------
const std::string &CatBreed::GetName() const {
    return mName;
}

// ------------------------------------------------------------------------------------------------
const std::string &CatBreed::GetOriginCountry() const {
    return mOriginCountry;
}

// ------------------------------------------------------------------------------------------------
CatBreed::CoatLength CatBreed::GetCoatLength() const {
    return mCoatLength;
}

// ------------------------------------------------------------------------------------------------
float CatBreed::GetMinWeightKg() const {
    return mMinWeightKg;
}

// ------------------------------------------------------------------------------------------------
float CatBreed::GetMaxWeightKg() const {
    return mMaxWeightKg;
}

// ------------------------------------------------------------------------------------------------
unsigned int CatBreed::GetMinLifespan() const {
    return mMinLifespan;
}

// ------------------------------------------------------------------------------------------------
unsigned int CatBreed::GetMaxLifespan() const {
    return mMaxLifespan;
}

// ------------------------------------------------------------------------------------------------
std::string CatBreed::ToString() const {
    std::ostringstream stream;
    stream << mName << " (" << mOriginCountry << "), "
           << CoatLengthToString(mCoatLength) << " coat, "
           << mMinWeightKg << "-" << mMaxWeightKg << " kg, "
           << mMinLifespan << "-" << mMaxLifespan << " years";
    return stream.str();
}

// ------------------------------------------------------------------------------------------------
const char *CatBreed::CoatLengthToString(CoatLength coatLength) {
    switch (coatLength) {
    case CoatLength::Hairless:
        return "hairless";
    case CoatLength::Short:
        return "short";
    case CoatLength::Medium:
        return "medium";
    case CoatLength::Long:
        return "long";
    default:
        break;
    }
    return "unknown";
}

} // namespace Assimp
