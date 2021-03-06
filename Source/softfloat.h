// SPDX-License-Identifier: Apache-2.0
// ----------------------------------------------------------------------------
// Copyright 2011-2020 Arm Limited
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy
// of the License at:
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.
// ----------------------------------------------------------------------------

/**
 * @brief Soft-float library for IEEE-754.
 */

#ifndef SOFTFLOAT_H_INCLUDED

#define SOFTFLOAT_H_INCLUDED

#if defined __cplusplus
extern "C"
{
#endif

#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#include <cstdint>

uint32_t clz32(uint32_t p);

/* targets that don't have UINT32_C probably don't have the rest of C99s stdint.h */
#ifndef UINT32_C
	#define PASTE(a) a
	#define UINT64_C(a) PASTE(a##ULL)
	#define UINT32_C(a) PASTE(a##U)
	#define INT64_C(a) PASTE(a##LL)
	#define INT32_C(a) a

	#define PRIX32 "X"
	#define PRId32 "d"
	#define PRIu32 "u"
	#define PRIX64 "LX"
	#define PRId64 "Ld"
	#define PRIu64 "Lu"

#endif

	/*	sized soft-float types. These are mapped to the sized integer types of C99, instead of C's
		floating-point types; this is because the library needs to maintain exact, bit-level control on all
		operations on these data types. */
	typedef uint16_t sf16;
	typedef uint32_t sf32;

	/* the five rounding modes that IEEE-754r defines */
	typedef enum
	{
		SF_UP = 0,				/* round towards positive infinity */
		SF_DOWN = 1,			/* round towards negative infinity */
		SF_TOZERO = 2,			/* round towards zero */
		SF_NEARESTEVEN = 3,		/* round toward nearest value; if mid-between, round to even value */
		SF_NEARESTAWAY = 4		/* round toward nearest value; if mid-between, round away from zero */
	} roundmode;

	/* narrowing float->float conversions */
	sf16 sf32_to_sf16(sf32, roundmode);

	/* widening float->float conversions */
	sf32 sf16_to_sf32(sf16);

	sf16 float_to_sf16(float, roundmode);
	float sf16_to_float(sf16);


#if defined __cplusplus
}
#endif

#endif
