
#include "unittest.h"

#include <iostream>
#include <queue>
#include <string>

#include "log4cpp/Category.hh"
#include "log4cpp/Priority.hh"

#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/StringQueueAppender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/RollingFileAppender.hh"
#include "log4cpp/Win32DebugAppender.hh"
#include "log4cpp/NTEventLogAppender.hh"

#include "log4cpp/BasicLayout.hh"
#include "log4cpp/SimpleLayout.hh"
#include "log4cpp/PatternLayout.hh"

UNITTEST(OstreamAppender)
{
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&std::cout);

    osAppender->setLayout(new log4cpp::SimpleLayout());

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(osAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
} 

UNITTEST(StringQueueAppender)
{
    log4cpp::StringQueueAppender* strQAppender = new log4cpp::StringQueueAppender("strQAppender");

    log4cpp::PatternLayout *pLayput = new log4cpp::PatternLayout();

    pLayput->setConversionPattern("%d: %p %2c: %m%n");

    strQAppender->setLayout(pLayput);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(strQAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    std::queue<std::string>& myStrQ =strQAppender->getQueue();
    while(!myStrQ.empty())
    {
        std::cout<<myStrQ.front();
        myStrQ.pop();
    }

    log4cpp::Category::shutdown();
}

UNITTEST(FileAppender)
{
    log4cpp::FileAppender* fileAppender = new log4cpp::FileAppender("fileAppender","testfile.log");

    log4cpp::PatternLayout *pLayput = new log4cpp::PatternLayout();

    pLayput->setConversionPattern("%d: %p %2c: %m%n");

    fileAppender->setLayout(pLayput);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(fileAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}

UNITTEST(RollingFileAppender)
{
    log4cpp::RollingFileAppender* rolefileAppender = new log4cpp::RollingFileAppender("rolefileAppender","testrollfile.log");

    log4cpp::PatternLayout *pLayput = new log4cpp::PatternLayout();

    pLayput->setConversionPattern("%d: %p %2c: %m%n");

    rolefileAppender->setLayout(pLayput);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(rolefileAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}

UNITTEST(Win32DebugAppender)
{
    log4cpp::Win32DebugAppender* win32DebugAppender = new log4cpp::Win32DebugAppender("win32debugAppender");

    log4cpp::PatternLayout *pLayput = new log4cpp::PatternLayout();

    pLayput->setConversionPattern("%d: %p %2c: %m%n");

    win32DebugAppender->setLayout(pLayput);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(win32DebugAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}

UNITTEST(NTEventLogAppender)
{
    log4cpp::NTEventLogAppender* ntEventAppender = new log4cpp::NTEventLogAppender("ntdebugAppender","testNtDebugLog4cpp");

    log4cpp::PatternLayout *pLayput = new log4cpp::PatternLayout();

    pLayput->setConversionPattern("%d: %p %2c: %m%n");

    ntEventAppender->setLayout(pLayput);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(ntEventAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}

/*
 * Appender  �б�
 *  log4cpp::IdsaAppender                // ���͵�IDS����
 *  log4cpp::FileAppender                // ������ļ�
 *  log4cpp::RollingFileAppender         // ������ؾ��ļ��������ļ�����ĳ����С��ؾ�
 *  log4cpp::OstreamAppender             // �����һ��ostream��
 *  log4cpp::RemoteSyslogAppender        // �����Զ��syslog������
 *  log4cpp::StringQueueAppender         // �ڴ����
 *  log4cpp::SyslogAppender              // ����syslog
 *  log4cpp::Win32DebugAppender          // ���͵�ȱʡϵͳ������
 *  log4cpp::NTEventLogAppender          // ���͵�win�¼���־
*/
