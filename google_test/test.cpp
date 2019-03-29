#include "pch.h"
#include "../rlist.h"
#include "../t_list.h"
#include "../t_vector.h"
#include "../t_vector_sorted.h"
#include "../t_hash.h"

TEST(RingList, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//TEST(RingList, can_create_table) {      ///////////error_destructor
//	ASSERT_NO_THROW(rlist<int> a);
//}

//TEST(RingList, can_check_empty) {
//	rlist<int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(RingList, can_add_data) {
//	int x = 1;
//	rlist<int> a;
//	ASSERT_NO_THROW(a.push(x));
//}

//TEST(RingList, can_get_data) {
//	rlist<int> a;
//	int x = 1;
//	a.push(x);
//	int y = a.get();
//	EXPECT_EQ(x, y);
//}

//TEST(RingList, can_clear) {
//	rlist<int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(RingList, can_pop_data) {
//	rlist<int> a;
//	a.push(1);
//	ASSERT_NO_THROW(a.pop());
//}




//TEST(ListTable, can_create_list)
//{
//	ASSERT_NO_THROW(t_list<int, int> a);
//}

//TEST(ListTable, can_check_empty)
//{
//	t_list<int, int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(ListTable, can_add_nexus)
//{
//	t_list<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	ASSERT_NO_THROW(a.add(x));
//}

//TEST(ListTable, can_remove_data)
//{
//	t_list<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	ASSERT_NO_THROW(a.remove(1));
//}
//
//TEST(ListTable, can_clear_table)
//{
//	t_list<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	ASSERT_NO_THROW(a.clear());
//}

//TEST(ListTable, can_get_data)
//{
//	t_list<int, int> a;
//	Nexus<int, int> x;
//	Nexus<int, int> y;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	a.get(1, y);
//	EXPECT_EQ(x, y);
//}

//TEST(ListTable, cant_get_data)              //////////////////
//{
//	t_list<int, int> a;
//	Nexus<int, int> x;
//	Nexus<int, int> y;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	EXPECT_EQ(false, a.get(1, y));
//}

//TEST(ListTable, exist)
//{
//	t_list<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	EXPECT_EQ(true, a.exist(1));
//}




//TEST(VectorTable, can_create_table) {
//	ASSERT_NO_THROW(t_vector<int, int> a);
//}

//TEST(VectorTable, can_add_data) 
//{
//	t_vector<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	ASSERT_NO_THROW(a.add(x));
//}

//TEST(VectorTable, can_check_empty) 
//{
//	t_vector<int, int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(VectorTable, can_remove_data)
//{
//	t_vector<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	ASSERT_NO_THROW(a.remove(1));
//}

//TEST(VectorTable, can_clear_table)
//{
//	t_vector<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	ASSERT_NO_THROW(a.clear());
//}

//TEST(VectorTable, can_get_data)
//{
//	t_vector<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	Nexus<int, int> y;
//	a.get(1, y);
//	EXPECT_EQ(x, y);
//}

//TEST(VectorTable, cant_get_data)
//{
//	t_vector<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	Nexus<int, int> y;
//	EXPECT_EQ(false, a.get(1, y));
//}

//TEST(VectorTable, exist)
//{
//	t_vector<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	EXPECT_EQ(true, a.exist(1));
//}




//TEST(VectorTableSort, can_create_table) {
//	ASSERT_NO_THROW(t_vector_sorted<int, int> a);
//}

//TEST(VectorTableSort, can_add_data) 
//{
//	t_vector_sorted<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	ASSERT_NO_THROW(a.add(x));
//}

//TEST(VectorTableSort, can_check_empty) 
//{
//	t_vector_sorted<int, int> a;
//	EXPECT_EQ(true, a.empty());
//}

//TEST(VectorTableSort, can_remove_data)
//{
//	t_vector_sorted<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	ASSERT_NO_THROW(a.remove(1));
//}

//TEST(VectorTableSort, can_clear_table)
//{
//	t_vector_sorted<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	ASSERT_NO_THROW(a.clear());
//}

//TEST(VectorTableSort, can_get_data)
//{
//	t_vector_sorted<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	Nexus<int, int> y;
//	a.get(1, y);
//	EXPECT_EQ(x, y);
//}

//TEST(VectorTableSort, cant_get_data)
//{
//	t_vector_sorted<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	Nexus<int, int> y;
//	EXPECT_EQ(false, a.get(1, y));
//}

//TEST(VectorTableSort, exist)
//{
//	t_vector_sorted<int, int> a;
//	Nexus<int, int> x;
//	x.data = 1; x.key = 1;
//	a.add(x);
//	EXPECT_EQ(true, a.exist(1));
//}





//TEST(HashTable, can_create_table) {
//	ASSERT_NO_THROW(hash_table<int> a);
//}
//
//TEST(HashTable, can_add_data) 
//{
//	hash_table<int> a;
//	Nexus2<int> x;
//	x.data = 1; x.key = "1";
//	ASSERT_NO_THROW(a.add(x));
//}
//
//TEST(HashTable, can_check_empty) 
//{
//	hash_table<int> a;
//	EXPECT_EQ(true, a.empty());
//}
//
//TEST(HashTable , can_remove_data)
//{
//	hash_table<int> a;
//	Nexus2<int> x;
//	x.data = 1; x.key = "1";
//	ASSERT_NO_THROW(a.remove("1"));
//}
//
//TEST(HashTable, can_clear_table)
//{
//	hash_table<int> a;
//	Nexus2<int> x;
//	x.data = 1; x.key = "1";
//	a.add(x);
//	ASSERT_NO_THROW(a.clear());
//}
//
//TEST(HashTable, can_get_data)
//{
//	hash_table<int> a;
//	Nexus2<int> x;
//	x.data = 1; x.key = "1";
//	a.add(x);
//	Nexus2<int> y;
//	a.get("1", y);
//	EXPECT_EQ(x, y);
//}
//
//TEST(HashTable, cant_get_data)
//{
//	hash_table<int> a;
//	Nexus2<int> x;
//	x.data = 1; x.key = "1";
//	a.add(x);
//	Nexus2<int> y;
//	EXPECT_EQ(false, a.get("1", y));
//}
//
//TEST(HashTable, exist)
//{
//	hash_table<int> a;
//	Nexus2<int> x;
//	x.data = 1; x.key = "1";
//	a.add(x);
//	EXPECT_EQ(true, a.exist("1"));
//}





//TEST(TreeTable, can_create_table) {
//	ASSERT_NO_THROW(hash_table<int> a);
//}
//


TEST(RingList, END) {
	system("pause");
}