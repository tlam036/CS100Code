#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "iterator.hpp"
#include "visitor.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "paren.hpp"
#include "trunc.hpp"
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"

TEST(CountVisitorTest, OpTest) {
	Base* op = new Op(4);
	
	Decorator* dummy = new Ceil(op);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, RandTest) {
	Base* rnd = new Rand();
	
	Decorator* dummy = new Ceil(rnd);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->rand_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, MultBinaryTest) {
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	
	Base* temp = new Mult(num1, num2);
	Decorator* dummy = new Ceil(temp);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->mult_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, DivBinaryTest) {
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	
	Base* temp = new Div(num1, num2);
	Decorator* dummy = new Ceil(temp);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->div_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, AddBinaryTest) {
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	
	Base* temp = new Add(num1, num2);
	Decorator* dummy = new Ceil(temp);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->add_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, SubBinaryTest) {
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	
	Base* temp = new Sub(num1, num2);
	Decorator* dummy = new Ceil(temp);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->sub_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, PowBinaryTest) {
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	
	Base* temp = new Pow(num1, num2);
	Decorator* dummy = new Ceil(temp);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->pow_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, CeilUnaryTest) {
	Base* num1 = new Op(3);
	Base* ceil = new Ceil(num1);
	Decorator* dummy = new Ceil(ceil);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 1);
}

TEST(CountVisitorTest, FloorUnaryTest) {
	Base* num1 = new Op(3);
	Base* floor = new Floor(num1);
	Decorator* dummy = new Ceil(floor);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->floor_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, AbsUnaryTest) {
	Base* num1 = new Op(3);
	Base* abs = new Abs(num1);
	Decorator* dummy = new Ceil(abs);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->abs_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, TruncUnaryTest) {
	Base* num1 = new Op(3);
	Base* trunc = new Trunc(num1);
	Decorator* dummy = new Ceil(trunc);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->trunc_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, ParenUnaryTest) {
	Base* num1 = new Op(3);
	Base* paren = new Paren(num1);
	Decorator* dummy = new Ceil(paren);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 1);
	EXPECT_EQ(visit->paren_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, ExpressionTreeTest) {
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* three = new Op(3);
	Base* two = new Op(2);
	Base* mult = new Mult(seven, four);
	Base* add = new Add(three, mult);
	Base* sub = new Sub(add, two);
	
	Decorator* dummy = new Ceil(sub);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 4);
	EXPECT_EQ(visit->mult_count(), 1);
	EXPECT_EQ(visit->add_count(), 1);
	EXPECT_EQ(visit->sub_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 0);
}

TEST(CountVisitorTest, DecoratorExpressionTreeTest) {
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* three = new Op(3);
	Base* two = new Op(2);
	Base* mult = new Mult(seven, four);
	Base* add = new Add(three, mult);
	Base* sub = new Sub(add, two);
	Base* ceil = new Ceil(sub);
	
	Decorator* dummy = new Ceil(ceil);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 4);
	EXPECT_EQ(visit->mult_count(), 1);
	EXPECT_EQ(visit->add_count(), 1);
	EXPECT_EQ(visit->sub_count(), 1);
	EXPECT_EQ(visit->ceil_count(), 1);
}

TEST(CountVisitorTest, ComplexExpressionTreeTest) {
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* three = new Op(3);
	Base* two = new Op(2);
	Base* mult = new Mult(seven, four);
	Base* add = new Add(three, mult);
	Base* sub = new Sub(add, two);
	Base* ceil = new Ceil(sub);
	
	Base* pow = new Pow(ceil, two);
	Base* add1 = new Add(three, pow);
	Base* sub1 = new Sub(add1, two);
	Base* floor = new Floor(sub1);
	
	Base* rand = new Rand();
	Base* pow1 = new Pow(rand, floor);
	Base* add2 = new Add(three, pow1);
	Base* sub2 = new Sub(add2, two);
	Base* abs = new Abs(sub2);
	
	Base* rand1 = new Rand();
 	Base* div = new Div(rand1, abs);
	Base* add3 = new Add(three, div);
	Base* sub3 = new Sub(add3, two);
	Base* trunc = new Trunc(sub3);
	
	Base* rand2 = new Rand();
 	Base* div1 = new Div(rand2, trunc);
	Base* add4 = new Add(three, div1);
	Base* sub4 = new Sub(add4, two);
	Base* paren = new Paren(sub4);
	
	Decorator* dummy = new Ceil(paren);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(it->is_done() == false){
		it->current()->accept(visit);
		it->next();
	}
	
	EXPECT_EQ(visit->op_count(), 13);
	EXPECT_EQ(visit->rand_count(), 3);
	EXPECT_EQ(visit->mult_count(), 1);
	EXPECT_EQ(visit->div_count(), 2);
	EXPECT_EQ(visit->add_count(), 5);
	EXPECT_EQ(visit->sub_count(), 5);
	EXPECT_EQ(visit->pow_count(), 2);
	EXPECT_EQ(visit->ceil_count(), 1);
	EXPECT_EQ(visit->floor_count(), 1);
	EXPECT_EQ(visit->abs_count(), 1);
	EXPECT_EQ(visit->paren_count(), 1);
	EXPECT_EQ(visit->trunc_count(), 1);
}

#endif
