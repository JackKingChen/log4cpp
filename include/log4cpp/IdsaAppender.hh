/*
 * IdsaAppender.hh
 *
 * Copyright 2000, Marc Welz
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4CPP_IDSAAPPENDER_HH
#define _LOG4CPP_IDSAAPPENDER_HH

#include <string>
#include <stdarg.h>
#include <idsa.h>
#include "log4cpp/Appender.hh"

namespace log4cpp {

    class IdsaAppender : public Appender {
        public:

        /**
         * Instantiate an IdsaAppender with given name and name.
         * Unlike the syslog API, idsa allows multiple connections.
         * @param name The name of the Appender
         * @param idsaName The service parameter of idsa
         **/         
        IdsaAppender(const string& name, const string& idsaName);
        virtual ~IdsaAppender();

        /**
         * Sends a LoggingEvent to idsa.
         * @param event the LoggingEvent to log.
         **/
        virtual void doAppend(const LoggingEvent& event);

        /**
         * Calls idsa_open() and idsa_close()
         **/
        virtual bool reopen();

        /**
         * Calls idsa_close()
         **/
        virtual void close();

        /**
         * The IdsaAppender does its own Layout.
         * @returns false
         **/
        virtual bool requiresLayout() const;

        virtual void setLayout(Layout* layout);

        protected:
        
        /**
         * Calls idsa_open().
         **/
        virtual void open();

        const string _idsaName;

        IDSA_CONNECTION *_idsaConnection;

    };
}

#endif // _LOG4CPP_IDSAAPPENDER_HH
