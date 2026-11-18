# 🎁 Gifter

Gifter is a console application that helps people find gift ideas for the important people in their lives. Users describe who they are shopping for, and Gifter suggests gifts that suit that person's age and gender, one idea at a time.

It is a C++ project completed in January 2023, during my studies at Transilvania University of Brașov.

## 💡 Why this project

Choosing a gift is harder than it sounds. It is easy to get stuck between too many options or to keep coming back to the same few ideas. Gifter narrows the choice down to gifts that actually fit the person, and lets the user build a short list of favorites to decide from.

On the technical side, the project was a way to practice object-oriented programming in C++: designing a family of related classes, keeping the program logic organized and handling errors cleanly.

## ✨ What it does

👤 **Personal accounts.** Each user signs up with a username and password, and can log back in later.

🧑‍🤝‍🧑 **People profiles.** Users add the people they are shopping for, with a name, gender and age group from baby to elder, and can come back to previous profiles at any time.

🎯 **Matched suggestions.** From a catalog of 13 gift types, such as watches, books, perfume, toys and bicycles, Gifter only suggests the ones that suit the selected person, in a random order.

❤️ **Liked gifts list.** Users answer each suggestion with a yes or a skip, and can review their liked gifts at any point.

## 🛠️ How it was built

Gifter is written in C++. Every gift type is its own class built on a shared Gift base class, which makes it easy to add new gifts without changing the rest of the program. A Manager class controls the menus and the flow of the app, and custom exceptions handle cases such as a username that does not exist.

| Area | Tools |
|---|---|
| Language | C++ |
| Concepts | Object-oriented design, inheritance, exception handling, STL containers |
| Environment | Visual Studio |
