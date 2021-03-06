// counter.h

/**
*    Copyright (C) 2008-2012 10gen Inc.
*
*    This program is free software: you can redistribute it and/or  modify
*    it under the terms of the GNU Affero General Public License, version 3,
*    as published by the Free Software Foundation.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Affero General Public License for more details.
*
*    You should have received a copy of the GNU Affero General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "mongo/platform/atomic_word.h"

namespace mongo {

    class Counter64 {
    public:
        
        void increment() { _counter.addAndFetch(1); }
        
        long long get() const { return _counter.load(); }
        
        operator long long() const { return get(); }
    private:
        AtomicInt64 _counter;
    };
}
