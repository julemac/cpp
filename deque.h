#ifndef MATRIX_H
#define MATRIX_H

/** @file containerWrapper.h
 *  @mainpage Porownanie wydajnosci kontenerow standardowych:
Klasa-wrapper ma zaimplementowac metody, ktore zawiera klasa abstrakcyjna IContainerWrapper.
Implementujac kazda z metod nalezy zmieniac odpowiadajace im stale preprocesora z 0 na 1.
Dzieki temu kolejne testy beda przechodzic.

Zaleznie od uzywanego pod spodem kontenera bedziemy mieli dostepne rozne metody,
czesc metod do zaimplementowania mozna w sposob przezroczysty przekazac do wykonania
uzywanemu kontenerowi, ktory dana metode juz ma zaimplementowana.
Jednakze czesc metod nie jest zaimplementowana, do tego trzeba juz uzyc internetu.

Odsylam do [dokumentacji standardowych kontenerow](https://en.cppreference.com/w/cpp/container),
oraz do [artykulu robiacego benchmark](https://baptiste-wicht.com/posts/2017/05/cpp-containers-benchmark-vector-list-deque-plf-colony.html).
____________________________________________________________________________________

## Do rozwazenia dla zaawansowanych:
1. Gdzie by sie przydal std::optional?
2. Co by nam dala pula pamieci?
3. Zachecam do poeksperymentowania z typem `value_type` i z rozmiarem elementow - czy cos to zmienia?
4. Dlaczego `pop_front` z biblioteki standardowej zwraca `void`?
____________________________________________________________________________________
## Uwaga:
1. Zachecam do uzywania czego sie da z biblioteki standardowej.
2. Metody większe niż 1-linijkowe powinny być zadeklarowane w klasie,
   zdefiniowane poza klasą w pliku zrodlowym.
3. Obiekty typów klasowych powinny być w miarę możliwości przekazywane
   w argumentach funkcji przez referencję do stalej,
4. Proszę stosować słówko "const" w odpowiednich miejscach.
5. W pliku naglowkowym prosze nie wlaczac dodatkowych naglowkow typu:
   <iostream>, <algorithm> - takie rzeczy powinny byc w pliku zrodlowym
6. Prosze aby w pliku naglowkowym nie bylo `using namespace std;`, w zrodlowym moze.
7. Testy nie testuja przypadkow wyjatkowych, ale jak ktos umie warto zabezpieczyc metody
   na dziwne uzycie.
8. W kodzie sa fragmenty -niespodzianki.
   Powiem o tym na zajeciach (a w razie czego prosze o przypomnienie)

Mozna tworzyc dowolna ilosc metod pomocniczych, jednakze aby byly one prywatne.
____________________________________________________________________________________
## Punktacja:
Liczy sie przejście testów, aczkolwiek dobrze jakby tez nie bylo warningow i wyciekow pamieci
**/

#include <vector>
#include <list>
#include <deque>
#include <cstddef> // std::size_t
#include <cstdint> // std::int64_t

#define IMPLEMENTED_DEFAULT_CONSTRUCTOR 0
#define IMPLEMENTED_CONSTRUCTOR_COPYING_FROM_ARRAY 0
#define IMPLEMENTED_PUSH_BACK 0
#define IMPLEMENTED_PUSH_FRONT 0
#define IMPLEMENTED_INSERT 0
#define IMPLEMENTED_AT 0
#define IMPLEMENTED_SORT 0
#define IMPLEMENTED_ERASE 0
#define IMPLEMENTED_COUNT 0
#define IMPLEMENTED_FIND 0
#define IMPLEMENTED_POP_FRONT 0


/// @brief Klasa abstrakcyjna - ma nam przypominac co zaimplementowac
class IContainerWrapper
{
public:
    using value_type = std::int64_t;

    virtual ~IContainerWrapper() = 0;

    virtual void push_back(const value_type& element) = 0;
    virtual void push_front(const value_type& element) = 0;

    virtual void insert(const value_type& element, size_t position) = 0;

    virtual size_t size() const = 0;

    virtual value_type& at(size_t position) = 0;

    virtual void sort() = 0;

    virtual void erase(size_t position) = 0;

    virtual value_type count() const = 0;

    virtual size_t find(const value_type& needle) const = 0;

    virtual value_type pop_front() = 0;
};

/// @brief Klasa ktora nic nie robi - aby sie kompilowalo
class LazyContainerWrapper: IContainerWrapper
{
public:
    LazyContainerWrapper() = default;
    LazyContainerWrapper(const value_type /*elements*/[], size_t /*N*/) {}

    void push_back(const value_type& /*element*/) override {}

    void push_front(const value_type& /*element*/) override {}

    void insert(const value_type& /*element*/, size_t /*position*/) override {}

    size_t size() const override { return {}; }

    value_type& at(size_t /*position*/) override
    {
        static value_type zero{};
        return zero;
    }

    void sort() override {}

    void erase(size_t /*position*/) override {}

    value_type count() const override { return {}; }

    size_t find(const value_type& /*needle*/) const override { return {}; }

    value_type pop_front() override { return {}; }
};

/// @brief Wrapper do std::deque
class DequeWrapper: IContainerWrapper
{
public:
    // TODO: ...
    DequeWrapper() = default;
    DequeWrapper(const value_type /*elements*/[], size_t /*N*/) {}

    void push_back(const value_type& element) override {
        impl_.push_back(element);
    }

    void push_front(const value_type& element) override {
        impl_.push_front(element);
    }

    void insert(const value_type& element, size_t position) override {
        impl_.insert(impl_.begin() + position,element);
    }

    size_t size() const override { 
        
        return impl_.size(); 
    }

    value_type& at(size_t position) override
    {
        //static value_type zero{};
        return impl_.at(position);
    }

    void sort() override;

    void erase(size_t position) override {
        impl_.erase(impl_.begin()+position)
    }

    value_type count() const override;

    size_t find(const value_type& /*needle*/) const override;

    value_type pop_front() override;

private:
    std::deque<value_type> impl_;
};

/// @brief Alias typu, ktory bedzie podlegac testom
using ContainerWrapper = DequeWrapper;

#endif // MATRIX_H
