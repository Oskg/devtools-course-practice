// Copyright 2022 Oskin Georgii

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Oskin_Georgii_ComplexNumTest, Zero_Init) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_NO_THROW(z.getRe());
    ASSERT_NO_THROW(z.getIm());
}

TEST(Oskin_Georgii_ComplexNumTest, Init_by_Constructor) {
    // Arrange
    double re = 3.0;
    double im = 1.0;

    // Act
    ComplexNumber cn_1(re, im);
    ComplexNumber cn_2 = cn_1;

    // Assert
    EXPECT_EQ(cn_2.getRe(), 3.0);
    EXPECT_EQ(cn_2.getIm(), 1.0);
}

