//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_GAMELOOPER_HXX
#define BOXESGAME_GAMELOOPER_HXX

#include <vector>
#include <map>
#include <boost/signals2.hpp>
#include <SDL2/SDL.h>

typedef Uint8 SubType;
typedef Uint32 Type;

enum {
    BOXESEVENT_ENTER_FRAME = SDL_LASTEVENT + 1,
    BOXESEVENT_LEAVE_FRAME,
    BOXESEVENT_CHECK_HORIZONTAL_SLIDE,
    BOXESEVENT_BOX_CLICKED,
    BOXESEVENT_VERTICAL_MOVEMENTS_APPLIED,
    BOXESEVENT_FORCE_HORIZONTAL_CHECK,
    BOXESGAME_ENDGAME
};

#define CALLBACK void(const char *ptr)
typedef std::function<CALLBACK> Callback;
typedef std::pair<SubType, Callback> Observer;
typedef std::vector<Observer> ObserverList;
typedef std::shared_ptr<boost::signals2::signal<CALLBACK> > Signal;

class GameLooper {
public:
    GameLooper();
    void observe(Type type, SubType event, Callback callback);
    void sendSignal(Type type, SubType event, const char *data);
    void loop();

    void exit();

private:
    bool shouldExit;
    std::map<std::tuple<Type, SubType>, Signal> observers;
    Signal &getSignal(Type type, SubType event);

};

#endif //BOXESGAME_GAMELOOPER_HXX
