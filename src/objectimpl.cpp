/*
 * Copyright 2003,2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <log4cxx/portability.h>

#ifdef LOG4CXX_HAVE_MS_THREAD
#include <windows.h>
#endif

#include <log4cxx/helpers/objectimpl.h>
#include <log4cxx/helpers/event.h>
#include <apr_atomic.h>

using namespace log4cxx::helpers;

ObjectImpl::ObjectImpl() : ref(0)
{
}

ObjectImpl::~ObjectImpl()
{
}

void ObjectImpl::addRef() const
{
	apr_atomic_inc32(&ref);
}

void ObjectImpl::releaseRef() const
{
	if (apr_atomic_dec32(&ref) == 0)
	{
		delete this;
	}
}
