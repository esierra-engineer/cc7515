#pragma once

#include <memory>
#include <type_traits>
#include <utility>

namespace std {

    // objetos normales
    template <typename T, typename... Args>
    typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
    make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    // arrays dinámicos T[]
    template <typename T>
    typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0, std::unique_ptr<T>>::type
    make_unique(std::size_t n) {
        using U = typename std::remove_extent<T>::type;
        return std::unique_ptr<T>(new U[n]());
    }

    // borra el uso con arrays estáticos (e.g. T[10])
    template <typename T, typename... Args>
    typename std::enable_if<std::extent<T>::value != 0, void>::type
    make_unique(Args&&...) = delete;

} // namespace std
