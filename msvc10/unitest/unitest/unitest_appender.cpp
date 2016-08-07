
#include "unittest.h"

#include <iostream>
#include <queue>
#include <string>

#include "log4cpp/Category.hh"
#include "log4cpp/Priority.hh"

#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/StringQueueAppender.hh"

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
}

UNITTEST(FileAppender)
{

}

UNITTEST(RollingFileAppender)
{

}

UNITTEST(Win32DebugAppender)
{

}

UNITTEST(NTEventLogAppender)
{

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

#if 0
UNITTEST(IdsaAppender)
{

}

UNITTEST(FileAppender)
{

}

UNITTEST(RollingFileAppender)
{

}

UNITTEST(OstreamAppender)
{

}

UNITTEST(RemoteSyslogAppender)
{

}

UNITTEST(StringQueueAppender)
{

}

UNITTEST(SyslogAppender)
{

}

UNITTEST(Win32DebugAppender)
{

}

UNITTEST(NTEventLogAppender)
{

}
#endif
