#include <vector>
#include <string>
#include "gtest/gtest.h"

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

void addStudent(std::vector<Student>& database, const Student& student) {
    database.push_back(student);
}

double calculateAverageAge(const std::vector<Student>& database) {
    if (database.empty()) {
        return 0.0;
    }
    int totalAge = 0;
    for (const Student& student : database) {
        totalAge += student.age;
    }
    return static_cast<double>(totalAge) / database.size();
}

// TESTS

// Empty database test
TEST(StudentTests, TestAverageAgeEmpty) {
    std::vector<Student> db;
    EXPECT_DOUBLE_EQ(calculateAverageAge(db), 0.0);
}

// Single student test
TEST(StudentTests, TestAverageAgeSingle) {
    std::vector<Student> db = { {"Alice", 20, "CS", 4.5} };
    EXPECT_DOUBLE_EQ(calculateAverageAge(db), 20.0);
}

// Multiple students test
TEST(StudentTests, TestAverageAgeMultiple) {
    std::vector<Student> db = {
        {"Alice", 20, "CS", 4.5},
        {"Bob", 22, "Math", 4.0},
        {"Charlie", 24, "Physics", 3.8}
    };
    EXPECT_DOUBLE_EQ(calculateAverageAge(db), (20 + 22 + 24) / 3.0);
}

// Test adding student to vector
TEST(StudentTests, TestAddStudent) {
    std::vector<Student> db;
    Student s{ "Diana", 21, "Biology", 4.2 };
    addStudent(db, s);
    ASSERT_EQ(db.size(), 1);
    EXPECT_EQ(db[0].name, "Diana");
    EXPECT_EQ(db[0].age, 21);
    EXPECT_EQ(db[0].major, "Biology");
    EXPECT_DOUBLE_EQ(db[0].gpa, 4.2);
}

// Test Student struct fields
TEST(StudentTests, TestStudentStructFields) {
    Student s{ "Eve", 19, "Chemistry", 3.9 };
    EXPECT_EQ(s.name, "Eve");
    EXPECT_EQ(s.age, 19);
    EXPECT_EQ(s.major, "Chemistry");
    EXPECT_DOUBLE_EQ(s.gpa, 3.9);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
