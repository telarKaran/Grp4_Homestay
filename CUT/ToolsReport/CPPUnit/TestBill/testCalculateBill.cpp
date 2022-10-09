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
#include <vector>
#include "Bookings.h"
#include <map>
// #include <bits/stdc++.h>

using namespace std;
using namespace CppUnit;

map<int,Bookings> bookings;

class TestBill : public CppUnit :: TestFixture {
    CPPUNIT_TEST_SUITE(TestBill);
    CPPUNIT_TEST(testCalculateBill);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testCalculateBill(void);

private:
    Bookings *mTestObj;
};

void TestBill::testCalculateBill(void) {

 
    //Sunny Test Cases
    CPPUNIT_ASSERT(42480 == mTestObj->calculateBill(bookings,100));
    CPPUNIT_ASSERT(41280 == mTestObj->calculateBill(bookings,101));
    CPPUNIT_ASSERT(2640 == mTestObj->calculateBill(bookings,102));
    CPPUNIT_ASSERT(41040 == mTestObj->calculateBill(bookings,103));
    CPPUNIT_ASSERT(525600 == mTestObj->calculateBill(bookings,104));
    
    //Rainy Test Cases
    CPPUNIT_ASSERT(-1 == mTestObj->calculateBill(bookings,105));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateBill(bookings,106));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateBill(bookings,107));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateBill(bookings,108));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateBill(bookings,109));

}

void TestBill::setUp(void) {
       mTestObj = new Bookings();
    

  
 
}

void TestBill::tearDown(void) {
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestBill );

int main(int argc, char* argv[]) {

    Bookings booking_new1(100,"KARAN","TELAR","GUJARAT","2022-10-10","2022-11-11",2);
    Bookings booking_new2(101,"CHIRAG","SUSHILKUMAR","America","2022-10-11","2022-11-11",3);
    Bookings booking_new3(102,"PUTREVU","NIKHIL","AP","2022-10-10", "2022-10-12",0);
    Bookings booking_new4(103,"VAMSHI","PRASAD","INDIA","2021-07-11","2021-08-11",1);
    Bookings booking_new5(104,"VAMSHI","PRASAD","INDIA","2015-10-10","2016-11-11",2);
    Bookings booking_new6(105,"SREEHARI","PS","UK","2019-60-50","2016-11-40",0);
    Bookings booking_new7(106,"SUSHANTH","SINGH","CANADA","2022-04-10","2022-05-11",5);
    Bookings booking_new8(107,"VIVEK","KUMAR","CHINA","2022/06/11","2022/07/11",4);
    Bookings booking_new9(108,"KRISHNA","CHAITANYA","fs","2022-10-10","2022-11-11",8);
    Bookings booking_new10(109,"AMAN","BHASKAR","North Korea","2022-33-15","2022-10-11",3);

    bookings.insert({100,booking_new1});
    bookings.insert({101,booking_new2});
     bookings.insert({102,booking_new3});
    bookings.insert({103,booking_new4});
     bookings.insert({104,booking_new5});
    bookings.insert({105,booking_new6});
     bookings.insert({106,booking_new7});
    bookings.insert({107,booking_new8});
     bookings.insert({108,booking_new9});
    bookings.insert({109,booking_new10});

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

