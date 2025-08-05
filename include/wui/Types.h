#pragma once


namespace wui {

    template <typename T>
    class XID {
    public:

        XID(T id) : m_id(id) {};

        T get() const { return m_id; }
        void set(T id) { m_id = id; }

    private:
        T m_id;
    };

}