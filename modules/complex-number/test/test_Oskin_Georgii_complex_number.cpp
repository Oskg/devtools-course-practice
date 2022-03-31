// Copyright 2022 Oskin Georgii

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Oskin_Georgii_ComplexNumTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_NO_THROW(z.getRe());
    ASSERT_NO_THROW(z.getIm());
}
