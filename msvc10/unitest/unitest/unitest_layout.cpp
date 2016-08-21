
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
 *   %c category��
 *   %d ���ڣ����ڿ��Խ�һ�������ø�ʽ���û����Ű�Χ������%d{%H:%M:%S,%l} ���� %d{%d %m %Y%H:%M:%S,%l}����������þ������ڸ�ʽ��������Ĭ�ϸ�ʽ��ʹ�á�Wed Jan 02 02:03:55 1980�������ڵĸ�ʽ������ANSI C����strftime�е�һ�¡���������һ����ʽ����%l����ʾ���룬ռ����ʮ����λ��
 *   %m ��Ϣ��
 *   %n ���з��������ƽ̨�Ĳ�ͬ����ͬ���������û�͸����
 *   %p ���ȼ���
 *   %r �Դ�layout��������ĺ�������
 *   %R ��1970��1��1��0ʱ��ʼ��ĿǰΪֹ��������
 *   %u ���̿�ʼ��ĿǰΪֹ��ʱ����������
 *   %x NDC��
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




