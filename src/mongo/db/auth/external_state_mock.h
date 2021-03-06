/**
*    Copyright (C) 2012 10gen Inc.
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

#include "mongo/base/disallow_copying.h"
#include "mongo/db/auth/external_state.h"

namespace mongo {

    /**
     * Mock of the ExternalState class used only for testing.
     */
    class ExternalStateMock : public ExternalState {
        MONGO_DISALLOW_COPYING(ExternalStateMock);

    public:
        ExternalStateMock() : _returnValue(false) {}

        virtual bool shouldIgnoreAuthChecks() const {
            return _returnValue;
        }

        void setReturnValueForShouldIgnoreAuthChecks(bool returnValue) {
            _returnValue = returnValue;
        }

    private:
        bool _returnValue;
    };

} // namespace mongo
