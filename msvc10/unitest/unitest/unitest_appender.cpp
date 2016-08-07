
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
 * Appender  列表：
 *  log4cpp::IdsaAppender                // 发送到IDS或者
 *  log4cpp::FileAppender                // 输出到文件
 *  log4cpp::RollingFileAppender         // 输出到回卷文件，即当文件到达某个大小后回卷
 *  log4cpp::OstreamAppender             // 输出到一个ostream类
 *  log4cpp::RemoteSyslogAppender        // 输出到远程syslog服务器
 *  log4cpp::StringQueueAppender         // 内存队列
 *  log4cpp::SyslogAppender              // 本地syslog
 *  log4cpp::Win32DebugAppender          // 发送到缺省系统调试器
 *  log4cpp::NTEventLogAppender          // 发送到win事件日志
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
