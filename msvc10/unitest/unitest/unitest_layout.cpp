
#include "unittest.h"

#include<iostream>
#include"log4cpp/Category.hh"
#include"log4cpp/OstreamAppender.hh"
#include"log4cpp/BasicLayout.hh"
#include"log4cpp/Priority.hh"

#include "log4cpp/SimpleLayout.hh"
#include "log4cpp/PatternLayout.hh"

using namespace std;


/*
*   typedef enum
    {
        EMERG  = 0,
        FATAL  = 0,
        ALERT  = 100,
        CRIT   = 200,
        ERROR  = 300,
        WARN   = 400,
        NOTICE =500,
        INFO   = 600,
        DEBUG  = 700,
        NOTSET =800
    }PriorityLevel;
 */
UNITTEST(BasicLayout)
{
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);

    osAppender->setLayout(new log4cpp::BasicLayout());

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(osAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("Hello log4cpp int aInfomation Message!");
    root.debug("Hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}

UNITTEST(SimpleLayout)
{
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);

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


/*
 * PatternLayout Format:
 *   %c category；
 *   %d 日期；日期可以进一步的设置格式，用花括号包围，例如%d{%H:%M:%S,%l} 或者 %d{%d %m %Y%H:%M:%S,%l}。如果不设置具体日期格式，则如下默认格式被使用“Wed Jan 02 02:03:55 1980”。日期的格式符号与ANSI C函数strftime中的一致。但增加了一个格式符号%l，表示毫秒，占三个十进制位。
 *   %m 消息；
 *   %n 换行符，会根据平台的不同而不同，但对于用户透明；
 *   %p 优先级；
 *   %r 自从layout被创建后的毫秒数；
 *   %R 从1970年1月1日0时开始到目前为止的秒数；
 *   %u 进程开始到目前为止的时钟周期数；
 *   %x NDC。
 */
UNITTEST(PatternLayout)
{
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);

    log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
    pLayout->setConversionPattern("%d: [%5p] %c: %m%n");

    osAppender->setLayout(pLayout);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.addAppender(osAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    root.error("Hello log4cpp in aError Message!");
    root.warn("Hello log4cpp in aWarning Message!");
    root.info("hello log4cpp int aInfomation Message!");
    root.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}




