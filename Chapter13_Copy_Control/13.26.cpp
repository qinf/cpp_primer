#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <initializer_list>
#include <stdexcept>
using std::string; using std::initializer_list; using std::vector;
using std::make_shared; using std::weak_ptr; using std::shared_ptr;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    using size_type = vector<string>::size_type;
    StrBlob(): data(shared_ptr<vector<string>>()) { }
    StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }
    StrBlob(const StrBlob &b);
    StrBlob& operator = (const StrBlob &b);
    size_type size() const { return data->size(); }
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
    bool empty() { return data->empty(); }
    void push_back(string &s) { data->push_back(s); }
    void pop_back();
    // visiting item
    string& front();
    string& back();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
//copy constructor
inline StrBlob::StrBlob(const StrBlob &b): data(make_shared<vector<string>>(*b.data)) { }
// copy-assignment operator
inline StrBlob& StrBlob::operator = (const StrBlob &b) {
    auto p = make_shared<vector<string>>(*b.data);
    std::swap(data, p);
    return *this;
}
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}
string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    StrBlobPtr(const StrBlob &a, const size_t sz = 0): wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(std::size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(std::size_t sz, const string& msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (sz >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
#endif
