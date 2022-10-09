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
#include <map>
#include <bits/stdc++.h>
#include "Bookings.h"
#include "rooms.h"
 
using namespace std;
using namespace CppUnit;

vector<Room> room;
map<int,Bookings> bookings; 

class TestApp : public CppUnit :: TestFixture {
    CPPUNIT_TEST_SUITE(TestApp);
    CPPUNIT_TEST(testDaysBetweenDates);
    CPPUNIT_TEST(testCalculateBill);
    CPPUNIT_TEST(testSearchRoom);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testDaysBetweenDates(void);
    void testSearchRoom(void);
    void testCalculateBill(void);

private:
    Bookings *mTestObj;
    Room *mTestObj2;
};

void TestApp::testDaysBetweenDates(void) {
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

void TestApp::testSearchRoom(void) {
    //Sunny Test Cases
    CPPUNIT_ASSERT(1 == mTestObj2->searchRoom(room, 302));
    CPPUNIT_ASSERT(1 == mTestObj2->searchRoom(room, 102));
    CPPUNIT_ASSERT(1 == mTestObj2->searchRoom(room, 109));
    CPPUNIT_ASSERT(1 == mTestObj2->searchRoom(room, 204));
    CPPUNIT_ASSERT(1 == mTestObj2->searchRoom(room, 107));
    //Rainy Test Cases
    CPPUNIT_ASSERT(0 == mTestObj2->searchRoom(room, 205));
    CPPUNIT_ASSERT(0 == mTestObj2->searchRoom(room, 209));
    CPPUNIT_ASSERT(0 == mTestObj2->searchRoom(room, 306));
    CPPUNIT_ASSERT(0 == mTestObj2->searchRoom(room, 206));
    CPPUNIT_ASSERT(0 == mTestObj2->searchRoom(room, 309));
}

void TestApp::testCalculateBill(void) {
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

void TestApp::setUp(void) {
    mTestObj = new Bookings();
    mTestObj2 = new Room();
}

void TestApp::tearDown(void) {
    delete mTestObj;
    delete mTestObj2;
}
//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestApp );

int main(int argc, char* argv[]) {

    Bookings booking_new1(100,"KARAN","TELAR","GUJARAT","2022-10-10","2022-11-11",2);
    Bookings booking_new2(101,"CHIRAG","SUSHILKUMAR","America","2022-10-11","2022-11-11",3);
    Bookings booking_new3(102,"PUTREVU","NIKHIL","AP","2022-10-10", "2022-10-12",0);
    Bookings booking_new4(103,"VAMSHI","PRASAD","INDIA","2021-07-11","2021-08-11",1);
    Bookings booking_new5(104,"VAMSHI","PRASAD","INDIA","2015-10-10","2016-11-11",2);
    Bookings booking_new6(105,"SREEHARI","PS","UK","2019-60-50","2016-11-40",0);
    Bookings booking_new7(106,"SUSHANTH","SINGH","CANADA","2022-04-10","2022-05-11",8);
    Bookings booking_new8(107,"VIVEK","KUMAR","CHINA","2022/06/11","2022/07/11",6);
    Bookings booking_new9(108,"KRISHNA","CHAITANYA","fs","2022-10-10","2022-11-11",8);
    Bookings booking_new10(109,"AMAN","BHASKAR","North Korea","2022-33-15","2022-10-11",9);

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


    ifstream fin("./roomsfile.txt");

    while(true)
    {
        string segment;
        if (!getline(fin, segment))
            break;

        stringstream transporter;
        transporter << segment;

        string idString;
		string idString1;
		string idString2;
		string idString3;
        getline(transporter, idString, ':');
        getline(transporter, idString1, ':');
		getline(transporter, idString2, ':');
		getline(transporter, idString3, ':');

       //cout<<idString<<" "<<idString1<<" "<<idString2<<" "<<idString3<<endl;
        // Room *p = new Room(idString,idString1,idString2,idString3);
       
        room.emplace_back((stoi)(idString),idString1,idString2,idString3);

    }

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
    ofstream xmlFileOut("cppTestResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}