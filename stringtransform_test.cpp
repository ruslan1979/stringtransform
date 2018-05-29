#include "stringtransform.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>


//testcase 1: remove empty word
BOOST_AUTO_TEST_CASE(test_1)
{
    string actual = "One two three";    
    stringtransform::removeword(actual, "");

    const string expected = "One two three";
    BOOST_REQUIRE_EQUAL(expected, actual);
}

//testcase 2 : remove any word
BOOST_AUTO_TEST_CASE(test_2)
{
    string actual = "One two three";
    stringtransform::removeword(actual, "two ");

    const string expected ("One three");
    BOOST_REQUIRE_EQUAL(expected, actual);
}

//#if defined(SOLUTION_ALL_TESTS)
//testcase 3: remove any word not irrespective of symbol's height
BOOST_AUTO_TEST_CASE(test_3)
{
    string actual = "One two three";
    stringtransform::removeword(actual, "onE");

    const string expected (" two three");
    BOOST_REQUIRE_EQUAL(expected, actual);
}

////testcase 4: remove multiple met words in a string
BOOST_AUTO_TEST_CASE(test_4)
{
    string actual = "One two three one four one five one One oNe";
    stringtransform::removeword(actual, "ONE");

    const string expected (" two three  four  five   ");
    BOOST_REQUIRE_EQUAL(expected, actual);
}

//testcase 5: sorting strings, lexicographic comparison
BOOST_AUTO_TEST_CASE(test_5)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);    
 
	vector<string> input_param = {
                                    "Кто поверит, что это бывает",
                                    "Кошка с мышкой в обниму гуляет",
                                    "Волк овечку катает в коляске",
                                    "А под вечер читает ей сказки"								  
								 };
   
    stringtransform::sort(input_param);

    const vector<string> expected= {
	                                "А под вечер читает ей сказки",
                                    "Волк овечку катает в коляске",
                                    "Кто поверит, что это бывает",
                                    "Кошка с мышкой в обниму гуляет"                                    
                                   };
							  
    for (string::size_type i = 0; i < input_param.size(); ++i) {
        BOOST_REQUIRE_EQUAL(input_param[i], expected[i]);
    }
}

//testcase 6: sorting strings
BOOST_AUTO_TEST_CASE(test_6)
{
	vector<string> input_param = {"One, two, three, four, five",
								        "I am flying in the sky.",
								        "I am a toy aeroplane,",
                                        "My name starts with A!"
								       };
    stringtransform::sort(input_param);

    const vector<string> expected = {"I am a toy aeroplane,",
								     "I am flying in the sky.",
								     "My name starts with A!",
								     "One, two, three, four, five"
                                    };
							  
    for (string::size_type i = 0; i < input_param.size(); ++i) {
        BOOST_REQUIRE_EQUAL(input_param[i], expected[i]);
    }    
}


//testcase 7: sorted vector's comparison
BOOST_AUTO_TEST_CASE(test_7)
{
	vector<string> input_param = {"One, two, three, four, five",
								  "I am flying in the sky.",
								  "I am a toy aeroplane,",
                                  "My name starts with A!"
								  };
    stringtransform::sort(input_param);

    const vector<string> expected = {"I am a toy aeroplane,",
								     "I am flying in the sky.",
								     "My name starts with A!",
								     "One, two, three, four, fiv"                                     
                                    };
   BOOST_TEST(input_param > expected);   
}