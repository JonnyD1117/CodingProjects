/*
 * The implementation for a more functional approach to FSM design was found in
 * https://silverweed.github.io/Functional_State_Machines_in_C++/ where the author
 * implements a more functional type of FSM which I have seen used before but never in
 * C++. The following code was lifted directly from that blog post.
 */

// StateFunction.hpp
#pragma once

#include <functional> // for std::function
#include <utility>    // for std::move

struct StateFunction {
    template <typename T>
    StateFunction(const T& f) : f(f) {}
    StateFunction(StateFunction&& s) = default;
    StateFunction(const StateFunction& s) = delete;

    // This Overload defines this struct as a "functor" when invoked directly as a function call
    StateFunction operator()() {
        return f();
    }

    // This Overload defines Move semantics during assignment to prevent copying
    StateFunction& operator=(StateFunction&& s) {
        f = std::move(s.f);
        return *this;
    }

    // This Overload defines something idk.
    StateFunction& operator=(const StateFunction&) = delete;

    // This Overload defines boolean comparisons for StateFunction struct.
    operator bool() const { return bool(f); }

    // Provides a callable std::function wrapper around the StateFunction Reference
    std::function<StateFunction()> f;
};
