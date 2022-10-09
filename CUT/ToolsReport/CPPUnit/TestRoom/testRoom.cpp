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
#include "rooms.h"
#include <vector>
 
using namespace std;
using namespace CppUnit;

vector<Room> room;

class TestRoom : public CppUnit :: TestFixture {
    CPPUNIT_TEST_SUITE(TestRoom);
    CPPUNIT_TEST(testSearchRoom);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testSearchRoom(void);

private:
    Room *mTestObj;
    Room *mTestObj2;
};

void TestRoom::testSearchRoom(void) {
    //Sunny Test Cases
    CPPUNIT_ASSERT(1 == mTestObj->searchRoom(room, 301));
    CPPUNIT_ASSERT(1 == mTestObj2->searchRoom(room, 102));
    CPPUNIT_ASSERT(1 == mTestObj->searchRoom(room, 109));
    CPPUNIT_ASSERT(1 == mTestObj->searchRoom(room, 204));
    CPPUNIT_ASSERT(1 == mTestObj->searchRoom(room, 107));
    //Rainy Test Cases
    CPPUNIT_ASSERT(0 == mTestObj->searchRoom(room, 205));
    CPPUNIT_ASSERT(0 == mTestObj->searchRoom(room, 209));
    CPPUNIT_ASSERT(0 == mTestObj->searchRoom(room, 306));
    CPPUNIT_ASSERT(0 == mTestObj->searchRoom(room, 206));
    CPPUNIT_ASSERT(0 == mTestObj->searchRoom(room, 309));
}

void TestRoom::setUp(void) {
    mTestObj = new Room(109,"standard","vacant","ac");
    mTestObj2 = new Room();
}

void TestRoom::tearDown(void) {
    delete mTestObj;
}



//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestRoom );

int main(int argc, char* argv[]) {

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
    ofstream xmlFileOut("cppDateResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

