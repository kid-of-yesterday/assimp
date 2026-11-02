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

/** @file  CatBreed.h
 *  @brief Declaration of the CatBreed data class.
 */
#pragma once
#ifndef AI_CATBREED_H_INC
#define AI_CATBREED_H_INC

#include <string>

namespace Assimp {

/// @brief Simple data class describing a cat breed.
class CatBreed {
public:
    /// @brief Describes the coat length of a breed.
    enum class CoatLength {
        Hairless = 0, ///< No or almost no fur.
        Short,        ///< Short coat.
        Medium,       ///< Semi-long coat.
        Long,         ///< Long coat.

        NumCoatLengths ///< The number of supported coat lengths.
    };

    /// @brief  The class constructor.
    /// @param[in] name           The breed name.
    /// @param[in] originCountry  The country the breed originates from.
    /// @param[in] coatLength     The coat length.
    /// @param[in] minWeightKg    The lower bound of the typical weight, in kg.
    /// @param[in] maxWeightKg    The upper bound of the typical weight, in kg.
    /// @param[in] minLifespan    The lower bound of the typical lifespan, in years.
    /// @param[in] maxLifespan    The upper bound of the typical lifespan, in years.
    /// @throw std::invalid_argument if a range is negative or its minimum exceeds its maximum.
    CatBreed(std::string name, std::string originCountry, CoatLength coatLength,
            float minWeightKg, float maxWeightKg,
            unsigned int minLifespan, unsigned int maxLifespan);

    ///	@brief  The class destructor.
    ~CatBreed() = default;

    /// @brief  Returns the breed name.
    const std::string &GetName() const;

    /// @brief  Returns the country of origin.
    const std::string &GetOriginCountry() const;

    /// @brief  Returns the coat length.
    CoatLength GetCoatLength() const;

    /// @brief  Returns the lower bound of the typical weight, in kg.
    float GetMinWeightKg() const;

    /// @brief  Returns the upper bound of the typical weight, in kg.
    float GetMaxWeightKg() const;

    /// @brief  Returns the lower bound of the typical lifespan, in years.
    unsigned int GetMinLifespan() const;

    /// @brief  Returns the upper bound of the typical lifespan, in years.
    unsigned int GetMaxLifespan() const;

    /// @brief  Returns a human-readable description of the breed.
    /// @return For example "Siamese (Thailand), short coat, 2.5-5.5 kg, 12-20 years".
    std::string ToString() const;

    /// @brief  Returns the name of a coat length.
    /// @param[in] coatLength   The coat length.
    /// @return The name, e.g. "short", or "unknown" for invalid values.
    static const char *CoatLengthToString(CoatLength coatLength);

private:
    std::string mName;
    std::string mOriginCountry;
    CoatLength mCoatLength;
    float mMinWeightKg;
    float mMaxWeightKg;
    unsigned int mMinLifespan;
    unsigned int mMaxLifespan;
};

} // namespace Assimp

#endif // AI_CATBREED_H_INC
