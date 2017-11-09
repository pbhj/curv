// Copyright Doug Moen 2016-2017.
// Distributed under The MIT License.
// See accompanying file LICENCE.md or https://opensource.org/licenses/MIT

#ifndef CURV_PATTERN_H
#define CURV_PATTERN_H

#include <curv/value.h>
#include <curv/frame.h>
#include <curv/gl_compiler.h>

namespace curv {

struct Environ;
struct Scope;
struct Phrase;
struct Context;

struct Pattern : public Shared_Base
{
    Shared<const Phrase> source_;

    Pattern(Shared<const Phrase> s) : Shared_Base(), source_(std::move(s)) {}

    virtual void analyze(Environ&) = 0;
    virtual void exec(Value* slots, Value, const Context&, Frame&) = 0;
    virtual void gl_exec(GL_Value, const Context&, GL_Frame&);
};

Shared<Pattern> make_pattern(const Phrase&, Scope&, unsigned unitno);

} // namespace
#endif // header guard