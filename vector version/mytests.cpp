#include "studentas.h" // Include the header file of your class
#include "gtest/gtest.h" // Include the Google Test framework

// Test case for constructor and getters
TEST(StudentasTest, ConstructorAndGetters) {
    // Create a student object
    studentas stud("John", "Doe", {90, 85, 95}, 1, 90.0);

    // Validate the values returned by getter methods
    EXPECT_EQ(stud.getVardas(), "John");
    EXPECT_EQ(stud.getPavarde(), "Doe");
    EXPECT_EQ(stud.getNdrez(), std::vector<int>({90, 85, 95}));
    EXPECT_EQ(stud.getErez(), 1);
    EXPECT_DOUBLE_EQ(stud.getGbalas(), 90.0);
}

// Test case for setter methods
TEST(StudentasTest, Setters) {
    // Create a student object
    studentas stud;

    // Set values using setter methods
    stud.setVardas("Jane");
    stud.setPavarde("Smith");
    stud.setNdrez({80, 75, 85});
    stud.setErez(2);
    stud.setGbalas(85.0);

    // Validate the values returned by getter methods
    EXPECT_EQ(stud.getVardas(), "Jane");
    EXPECT_EQ(stud.getPavarde(), "Smith");
    EXPECT_EQ(stud.getNdrez(), std::vector<int>({80, 75, 85}));
    EXPECT_EQ(stud.getErez(), 2);
    EXPECT_DOUBLE_EQ(stud.getGbalas(), 85.0);
}

// Test case for sorting exam results
TEST(StudentasTest, SortNdrez) {
    // Create a student object with unsorted exam results
    studentas stud;
    stud.setNdrez({70, 65, 75, 60, 80});

    // Sort the exam results
    stud.sortNdrez();

    // Validate that the exam results are sorted in ascending order
    EXPECT_EQ(stud.getNdrez(), std::vector<int>({60, 65, 70, 75, 80}));
}

// Add more test cases as needed

// Entry point for running the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
