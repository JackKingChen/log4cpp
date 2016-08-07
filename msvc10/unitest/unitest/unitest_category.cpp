
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

UNITTEST(Category)
{
    log4cpp::OstreamAppender* osAppender1 = new log4cpp::OstreamAppender("osAppender",&std::cout);
    log4cpp::OstreamAppender* osAppender2 = new log4cpp::OstreamAppender("osAppender",&std::cout);

    log4cpp::PatternLayout* pLayout1 = new log4cpp::PatternLayout();
    pLayout1->setConversionPattern("%d: %p %2c: %m%n");
    log4cpp::PatternLayout* pLayout2 = new log4cpp::PatternLayout();
    pLayout2->setConversionPattern("%d: %p %2c: %m%n");

    osAppender1->setLayout(pLayout1);
    osAppender2->setLayout(pLayout2);

    log4cpp::Category& root =log4cpp::Category::getRoot();

    root.setPriority(log4cpp::Priority::DEBUG);

    log4cpp::Category& sub1 =root.getInstance("sub1");
    log4cpp::Category& sub2 =root.getInstance("sub2");

    sub1.setPriority(log4cpp::Priority::DEBUG);
    sub2.setPriority(log4cpp::Priority::DEBUG);

    sub1.addAppender(osAppender1);
    sub2.addAppender(osAppender2);

    sub1.error("Hello log4cpp in aError Message!");
    sub1.warn("Hello log4cpp in aWarning Message!");
    sub2.info("hello log4cpp int aInfomation Message!");
    sub2.debug("hello log4cpp int aDebug Message!");

    log4cpp::Category::shutdown();
}
