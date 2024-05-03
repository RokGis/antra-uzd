#include "studentas.h"
#include "gtest/gtest.h"

// Testuojame konstruktorius ir get metodus
TEST(StudentasTest, ConstructorAndGetters) {
    std::vector<int> nd_rezultatai = {10, 8, 9};
    studentas stud("Vardas", "Pavarde", nd_rezultatai, 1, 9.5);

    EXPECT_EQ(stud.get_vardas(), "Vardas");
    EXPECT_EQ(stud.get_pavarde(), "Pavarde");
    EXPECT_EQ(stud.get_erez(), 1);
    EXPECT_DOUBLE_EQ(stud.get_gbalas(), 9.5);

    std::vector<int> nd_rezultatai_gauti = stud.get_ndrez();
    ASSERT_EQ(nd_rezultatai_gauti.size(), nd_rezultatai.size());
    for (int i = 0; i < nd_rezultatai.size(); ++i) {
        EXPECT_EQ(nd_rezultatai_gauti[i], nd_rezultatai[i]);
    }
}

// Testuojame copy konstruktorių
TEST(StudentasTest, CopyConstructor) {
    std::vector<int> nd_rezultatai = {10, 8, 9};
    studentas stud1("Vardas", "Pavarde", nd_rezultatai, 1, 9.5);
    studentas stud2 = stud1;

    EXPECT_EQ(stud1.get_vardas(), stud2.get_vardas());
    EXPECT_EQ(stud1.get_pavarde(), stud2.get_pavarde());
    EXPECT_EQ(stud1.get_erez(), stud2.get_erez());
    EXPECT_DOUBLE_EQ(stud1.get_gbalas(), stud2.get_gbalas());

    std::vector<int> nd_rezultatai_stud1 = stud1.get_ndrez();
    std::vector<int> nd_rezultatai_stud2 = stud2.get_ndrez();
    ASSERT_EQ(nd_rezultatai_stud1.size(), nd_rezultatai_stud2.size());
    for (int i = 0; i < nd_rezultatai_stud1.size(); ++i) {
        EXPECT_EQ(nd_rezultatai_stud1[i], nd_rezultatai_stud2[i]);
    }
}

// Testuojame move konstruktorių
TEST(StudentasTest, MoveConstructor) {
    std::vector<int> nd_rezultatai = {10, 8, 9};
    studentas stud1("Vardas", "Pavarde", nd_rezultatai, 1, 9.5);
    studentas stud2 = std::move(stud1);

    EXPECT_EQ(stud2.get_vardas(), "Vardas");
    EXPECT_EQ(stud2.get_pavarde(), "Pavarde");
    EXPECT_EQ(stud2.get_erez(), 1);
    EXPECT_DOUBLE_EQ(stud2.get_gbalas(), 9.5);

    std::vector<int> nd_rezultatai_gauti = stud2.get_ndrez();
    ASSERT_EQ(nd_rezultatai_gauti.size(), nd_rezultatai.size());
    for (int i = 0; i < nd_rezultatai.size(); ++i) {
        EXPECT_EQ(nd_rezultatai_gauti[i], nd_rezultatai[i]);
    }

    // stud1 turėtų būti tuščias
    EXPECT_TRUE(stud1.get_vardas().empty());
    EXPECT_TRUE(stud1.get_pavarde().empty());
    EXPECT_EQ(stud1.get_erez(), 0);
    EXPECT_DOUBLE_EQ(stud1.get_gbalas(), 0.0);
    EXPECT_TRUE(stud1.get_ndrez().empty());
}

// Testuojame priskyrimo operatorių
TEST(StudentasTest, AssignmentOperator) {
    std::vector<int> nd_rezultatai1 = {10, 8, 9};
    std::vector<int> nd_rezultatai2 = {5, 6, 7};
    studentas stud1("Vardas1", "Pavarde1", nd_rezultatai1, 1, 9.5);
    studentas stud2("Vardas2", "Pavarde2", nd_rezultatai2, 2, 8.0);
    stud2 = stud1;

    EXPECT_EQ(stud1.get_vardas(), stud2.get_vardas());
    EXPECT_EQ(stud1.get_pavarde(), stud2.get_pavarde());
    EXPECT_EQ(stud1.get_erez(), stud2.get_erez());
    EXPECT_DOUBLE_EQ(stud1.get_gbalas(), stud2.get_gbalas());

    std::vector<int> nd_rezultatai_stud1 = stud1.get_ndrez();
    std::vector<int> nd_rezultatai_stud2 = stud2.get_ndrez();
    ASSERT_EQ(nd_rezultatai_stud1.size(), nd_rezultatai_stud2.size());
    for (int i = 0; i < nd_rezultatai_stud1.size(); ++i) {
        EXPECT_EQ(nd_rezultatai_stud1[i], nd_rezultatai_stud2[i]);
    }
}
