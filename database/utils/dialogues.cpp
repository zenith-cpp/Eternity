#include "dialogues.h"
#include <iostream>

std::vector<std::string> dialogue_cv_general                = { // when respectability ranges from 30-60
    "Hello there. Do you require my assistance?", "What do you want from me?", "How's the weather?", "Hi.", "Greetings.", "How can I help?",
    "I don't know what you want, but it better be important.", "Time is the most valuable thing in the world. Speak."
};
std::vector<std::string> dialogue_cv_general_respectsPlayer = { // when respectability ranges from 60-100 (max)
    "Oh hi! Long time no see, friend. If you require my assistance, I am free.", "I got all the time in the world for you!",
    "You can tell me anything.", "If you need someone to talk to, I am always here.", "What can I do for you, best friend?"
};
std::vector<std::string> dialogue_cv_general_hatesPlayer    = { // when respectability is below 30
    "Talk, shithead.", "What the heck? Stop wasting my time and dont come any closer you nasty bug.", "Talk to me again and I'll hang you on that pole.",
    "You really expect me to forgive you after what you did? Fuck off.", "Please. NEVER come near me again.",
    "You're a psycho.", "Weirdo."
};
