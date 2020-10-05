#include "pch.h"
#include "..\Library\Curve.h"

//constructor
TEST(CurveConstructor, DefaultConstructor){
	lab2::Curve a1;
	ASSERT_EQ(2, a1.getP().c);
	ASSERT_EQ(1, a1.getP().m);
	//ASSERT_EQ(1, a1.getR());
}
TEST(CurveConstructor, InitConstructors){
	lab2::Curve a2(2, 3);
	lab2::Parameters p(2, 3);
	//ASSERT_EQ(3, a2.getP()); 
	ASSERT_EQ(2, a2.getP().c);
	ASSERT_EQ(3, a2.getP().m);
	lab2::Curve a3(p);
	ASSERT_EQ(2, a3.getP().c);
	ASSERT_EQ(3, a3.getP().m);
	//ASSERT_EQ(8, a3.getR());
	lab2::Curve a4(-4, -5);
	ASSERT_EQ(-4, a4.getP().c);
	ASSERT_EQ(-5, a4.getP().m);
	//ASSERT_EQ(3, a4.getR());
}
TEST(CurveConstructor, TestException){
	lab2::Parameters p(0, 0);
	ASSERT_EQ(0, p.c);
	ASSERT_EQ(0, p.m);
	ASSERT_ANY_THROW(lab2::Curve(0, 0));
}
// testing methods
TEST(CurveMethods, Setters){
	lab2::Curve a;
	lab2::Parameters p1(3, 2);
	a.setP(p1);
	ASSERT_EQ(3, a.getP().c);
	ASSERT_EQ(2, a.getP().m);
	lab2::Parameters p2(-3, -2);
	a.setP(p2);
	ASSERT_EQ(-3, a.getP().c);
	ASSERT_EQ(-2, a.getP().m);
	//a.setR(2);
	//ASSERT_EQ(2, a.getR());
	lab2::Parameters p3(0, 0);
	ASSERT_ANY_THROW(a.setP(p3));
}
TEST(CurveMethods, Parameters){
	lab2::Curve a1;
	const double PI = 3.14159, err = 0.001;
	ASSERT_NEAR(PI, a1.area(), err);
	ASSERT_EQ(1, a1.type());
	ASSERT_EQ(1, a1.distance(PI));
	//ASSERT_EQ(1, a1.f(1).c);
	//ASSERT_EQ(0, a1.f(1).m);
	//ASSERT_EQ(1, a1.f(0).x);
	//ASSERT_EQ(-1, a1.f(0).y);
	//ASSERT_ANY_THROW(a1.f(2));
	//ASSERT_STREQ("p^2 = 1.00", a1.frm());
	lab2::Curve a2(0, 2);
	ASSERT_NEAR(4, a2.area(), err);
	ASSERT_EQ(0, a2.type());
	//ASSERT_EQ(2.82843, a2.distance(0));
	ASSERT_ANY_THROW(a2.distance(4));
	lab2::Curve a3(0, 1);
	ASSERT_ANY_THROW(a2.distance(2));
	//ASSERT_EQ(5, a2.f(1).x);
	//ASSERT_EQ(1, a2.f(1).y);
	//ASSERT_NEAR(3 + sqrt(3), a2.f(0).x, err);
	//ASSERT_EQ(3 - sqrt(3), a2.f(0).y);
	//ASSERT_ANY_THROW(a2.f(-2));
	//ASSERT_STREQ("8.00cos(2*fi)", a2.frm());
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
