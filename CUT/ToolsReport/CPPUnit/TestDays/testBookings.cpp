#include <bits/stdc++.h>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include <iostream>
#include <string>
#include "Bookings.h"
#include <vector>
 
using namespace std;
using namespace CppUnit;


class TestBookings : public CppUnit :: TestFixture {
    CPPUNIT_TEST_SUITE(TestBookings);
    CPPUNIT_TEST(testDaysBetweenDates);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testDaysBetweenDates(void);

private:
    Bookings *mTestObj;
};

void TestBookings::testDaysBetweenDates(void) {
    //Sunny Test Cases
    CPPUNIT_ASSERT(5 == mTestObj->daysBetweenDates("2022/10/10", "2022/10/15"));
    CPPUNIT_ASSERT(7 == mTestObj->daysBetweenDates("2022/11/11", "2022/11/18"));
    CPPUNIT_ASSERT(9 == mTestObj->daysBetweenDates("2021/12/25", "2022/01/03"));
    CPPUNIT_ASSERT(4 == mTestObj->daysBetweenDates("2022/03/28", "2022/04/01"));
    CPPUNIT_ASSERT(1 == mTestObj->daysBetweenDates("2022/01/26", "2022/01/27"));
    //Rainy Test Cases
    CPPUNIT_ASSERT(-1 == mTestObj->daysBetweenDates("2019/08/10", "2019/08/03"));
    CPPUNIT_ASSERT(-1 == mTestObj->daysBetweenDates("2018/01/30", "2018/01/01"));
    CPPUNIT_ASSERT(-1 == mTestObj->daysBetweenDates("2020/04/22", "2020/04/14"));
    CPPUNIT_ASSERT(-1 == mTestObj->daysBetweenDates("2020/07/29", "2020/07/23"));
    CPPUNIT_ASSERT(-1 == mTestObj->daysBetweenDates("2021/11/03", "2021/11/02"));
}

void TestBookings::setUp(void) {
    mTestObj = new Bookings();
}

void TestBookings::tearDown(void) {
    delete mTestObj;
}



//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestBookings );

int main(int argc, char* argv[]) {

    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppDateResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

