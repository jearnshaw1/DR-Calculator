#ifndef OPTIONAL_H
#define OPTIONAL_H

namespace dr_calculator
{
    
template <typename T>
class optional
{
public:

    optional()
    {
    }

    optional( const T& Src )
    {
        T_ = new T( Src );
    }

    optional( T&& Src )
    {
        T_ = new T( Src );
    }

    const optional& operator=( const T& Rhs )
    {
        if( T_ )
        {
            *T_ = Rhs;
        }
        else
        {
            T_ = new T( Rhs );
        }
        return *this;
    }

    operator bool() const
    {
        return T_;
    }

    T operator*() const
    {
        return *T_;
    }

    T& get()
    {
        return *T_;
    }
		
    ~optional()
    {
        if( T_ )
        {
            delete T_;
        }
    }

private:

    T* T_;
};

}

#endif // OPTIONAL_H