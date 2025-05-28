#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/lecture_subscription.h"
#include "../main-project/processing.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	lecture_subscription* build_subscription(int start_hours, int start_minutes,  int finish_hours, int finish_minutes)
	{
		lecture_subscription* subscription = new lecture_subscription;
		subscription->start.hours = start_hours;
		subscription->start.minutes = start_minutes;
		subscription->finish.hours = finish_hours;
		subscription->finish.minutes = finish_minutes;
		return subscription;
	}

	//       
	void delete_subscription(lecture_subscription* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1) //     
		{
			lecture_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(12, 10, 14, 10); // 120 
			subscriptions[1] = build_subscription(14, 10, 16, 5); // 115
			subscriptions[2] = build_subscription(8, 0, 8, 45); // 45
			Assert::AreEqual(120, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod2) //     
		{
			lecture_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(8, 55, 9, 5); // 10 
			subscriptions[1] = build_subscription(11, 30, 12, 30); // 60 
			subscriptions[2] = build_subscription(14, 10, 14, 25); // 15
			Assert::AreEqual(60, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod3) //     
		{
			lecture_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(18, 30, 19, 40); // 70
			subscriptions[1] = build_subscription(15, 5, 15, 15); // 10
			subscriptions[2] = build_subscription(17, 0, 17, 40); // 40
			Assert::AreEqual(70, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod4) //     
		{
			lecture_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(9, 20, 9, 35); // 15 
			subscriptions[1] = build_subscription(9, 35, 10, 5); // 30
			subscriptions[2] = build_subscription(17, 30, 18, 30); // 60
			Assert::AreEqual(60, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

	};
}
