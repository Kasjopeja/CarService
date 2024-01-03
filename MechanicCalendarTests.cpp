#include "gtest/gtest.h"
#include "Calendar.h"
#include "Event.h"

TEST(CalendarTest, AddEvent) {
Calendar calendar;
Event event("Engine repair", "01-01-2023", "10-01-2023");

calendar.addEvent(event);

ASSERT_EQ(calendar.getEvents().size(), 1);
EXPECT_EQ(calendar.getEvents()[0], event);
}

TEST(CalendarTest, RemoveEvent) {
Calendar calendar;
Event event1("Oil change", "02-01-2023", "12-01-2023");
Event event2("Brake inspection", "03-01-2023", "15-01-2023");

calendar.addEvent(event1);
calendar.addEvent(event2);

calendar.removeEvent(1);

ASSERT_EQ(calendar.getEvents().size(), 1);
EXPECT_EQ(calendar.getEvents()[0], event1);
}

TEST(CalendarTest, DisplayEvents) {
testing::internal::CaptureStdout(); // Redirect cout to capture the output
Calendar calendar;
Event event("Tire rotation", "04-01-2023", "18-01-2023");

calendar.addEvent(event);

calendar.displayEvents();

std::string output = testing::internal::GetCapturedStdout();
EXPECT_EQ(output, "\n------------------------\n| Naprawy w kalendarzu |\n------------------------\nID: 1\nUsterka: Tire rotation\nData przyjęcia: 04-01-2023\nPlanowana data odbioru: 18-01-2023\n------------------------\n\n");
}

// Add more tests as needed
