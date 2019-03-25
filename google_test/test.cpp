#include "pch.h"
#include "../rlist.h"
#include "../t_list.h"
#include "../t_vector.h"

TEST(RingList, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(RingList, can_create_table) {
	ASSERT_NO_THROW(rlist<int> a);
}

//TEST(RingList, can_check_empty) {
//	rlist<int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(RingList, can_add_data) {
//	rlist<int> a;
//}

//TEST(RingList, can_get_data) {
//	rlist<int> a;
//}

//TEST(RingList, can_clear_table) {
//	rlist<int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(RingList, can_pop_data) {
//	rlist<int> a;
//}

//TEST(ListTable, can_create_list)
//{
//	ASSERT_NO_THROW(t_list<int, int> a);
//}

//TEST(ListTable, can_check_empty)
//{
//	t_list<int, int> a;
//}

//TEST(ListTable, can_add_nexus)
//{
//	t_list<int, int> a;
//}

//TEST(ListTable, can_remove_data)
//{
//	t_list<int, int> a;
//}

//TEST(ListTable, can_clear_table)
//{
//	t_list<int, int> a;
//}

//TEST(ListTable, can_get_data)
//{
//	t_list<int, int> a;
//}

//TEST(ListTable, cant_get_data)
//{
//	t_list<int, int> a;
//}

//TEST(ListTable, exist)
//{
//	t_list<int, int> a;
//}

//TEST(VectorTable, can_create_table) {
//	ASSERT_NO_THROW(t_vector<int, int> a);
//}

//TEST(VectorTable, can_add_data) {
//	t_vector<int, int> a;
//}

TEST(RingList, END) {
	system("pause");
}