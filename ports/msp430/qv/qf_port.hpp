/// @file
/// @brief QF/C++ port to MSP430, cooperative QV kernel
/// @cond
///***************************************************************************
/// Last updated for version 6.6.0
/// Last updated on  2019-07-30
///
///                    Q u a n t u m  L e a P s
///                    ------------------------
///                    Modern Embedded Software
///
/// Copyright (C) 2005-2019 Quantum Leaps. All rights reserved.
///
/// This program is open source software: you can redistribute it and/or
/// modify it under the terms of the GNU General Public License as published
/// by the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// Alternatively, this program may be distributed and modified under the
/// terms of Quantum Leaps commercial licenses, which expressly supersede
/// the GNU General Public License and are specifically designed for
/// licensees interested in retaining the proprietary status of their code.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <www.gnu.org/licenses>.
///
/// Contact information:
/// <www.state-machine.com/licensing>
/// <info@state-machine.com>
///***************************************************************************
/// @endcond

#ifndef QF_PORT_HPP
#define QF_PORT_HPP

// The maximum number of active objects in the application, see NOTE01
#define QF_MAX_ACTIVE        8

#define QF_EVENT_SIZ_SIZE    1
#define QF_EQUEUE_CTR_SIZE   1
#define QF_MPOOL_SIZ_SIZE    1
#define QF_MPOOL_CTR_SIZE    1
#define QF_TIMEEVT_CTR_SIZE  2

// QF interrupt disable/enable...
#define QF_INT_DISABLE()     __disable_interrupt()
#define QF_INT_ENABLE()      __enable_interrupt()

// QF critical section entry/exit...
#define QF_CRIT_STAT_TYPE    unsigned short
#define QF_CRIT_ENTRY(stat_) do { \
    (stat_) =  __get_interrupt_state(); \
    __disable_interrupt(); \
} while (false)
#define QF_CRIT_EXIT(stat_)  __set_interrupt_state(stat_)


#include <intrinsics.h> // intrinsic functions

#include "qep_port.hpp"   // QEP port
#include "qv_port.hpp"    // QV cooperative kernel port
#include "qf.hpp"         // QF platform-independent public interface

//****************************************************************************
// NOTE01:
// The maximum number of active objects QF_MAX_ACTIVE can be increased
// up to 64, if necessary. Here it is set to a lower level to save some RAM.
//

#endif // QF_PORT_HPP
