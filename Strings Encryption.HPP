
#pragma once

#include < string >
#include < vector >
#include < random >

extern char SE_RANDOM_KEY , SE_RANDOM_BUFFER [ 2048 ] ;

constexpr int SE_TIME_DATE_SEED = \
                                        ( \
                                            ( \
                                                __TIME__ [ 0 ]  - '0' + \
                                                __TIME__ [ 1 ]  - '0' + \
                                                __TIME__ [ 3 ]  - '0' + \
                                                __TIME__ [ 4 ]  - '0' + \
                                                __TIME__ [ 6 ]  - '0' + \
                                                __TIME__ [ 7 ]  - '0' \
                                            ) \
                                            + \
                                            ( \
                                                __DATE__ [ 0 ]  - '0' + \
                                                __DATE__ [ 1 ]  - '0' + \
                                                __DATE__ [ 2 ]  - '0' + \
                                                __DATE__ [ 4 ]  - '0' + \
                                                __DATE__ [ 5 ]  - '0' + \
                                                __DATE__ [ 7 ]  - '0' + \
                                                __DATE__ [ 8 ]  - '0' + \
                                                __DATE__ [ 9 ]  - '0' + \
                                                __DATE__ [ 10 ] - '0' \
                                            ) \
                                        ) \
                                        * \
                                        ( ( ( __TIME__ [ 6 ] - '0' ) < 2 ) ? ( 2 ) : ( __TIME__ [ 6 ] - '0' ) ) ;

template < int SE_VAL > struct SE_ENSURE_COMPILE_TIME
{

    enum : int
    {

        SE_VALUE = :: SE_VAL ,

    } ;

} ;

template < int ... SE_PACK > struct SE_INDEX_LIST ;

template < typename SE_INDEX_LIST , int SE_RIGHT > struct SE_APPEND ;

template < int ... SE_LEFT , int SE_RIGHT > struct SE_APPEND < :: SE_INDEX_LIST < SE_LEFT ... > , SE_RIGHT >
{

    typedef :: SE_INDEX_LIST < SE_LEFT ... , SE_RIGHT > SE_RESULT ;

} ;

template < int SE_N > struct SE_CONSTRUCT_INDEX_LIST
{

    typedef typename :: SE_APPEND < typename :: SE_CONSTRUCT_INDEX_LIST < SE_N - 1 > :: SE_RESULT , SE_N - 1 > :: SE_RESULT SE_RESULT ;

} ;

template < > struct SE_CONSTRUCT_INDEX_LIST < 0 >
{

    typedef :: SE_INDEX_LIST < > SE_RESULT ;

} ;

template < typename SE_INDEX_LIST > class SE_XOR_STRING ;

constexpr __forceinline char SE_ENCRYPT_CHARACTER ( char SE_CHARACTER , int SE_WHERE ) noexcept
{

    return SE_CHARACTER ^ SE_RANDOM_BUFFER [ SE_WHERE ] ;

} ;

template < int ... SE_INDEX > class SE_XOR_STRING < :: SE_INDEX_LIST < SE_INDEX ... > >
{

public:

    char SE_DATA [ sizeof ... ( SE_INDEX ) + SE_TIME_DATE_SEED ]
    {



    } ;

    constexpr __forceinline SE_XOR_STRING ( const char * const SE_STRING ) noexcept : \
        SE_DATA
        {

            :: SE_ENCRYPT_CHARACTER ( SE_STRING [ SE_INDEX ] , SE_INDEX ) ...

        }
    {



    } ;

    constexpr __forceinline :: std :: string SE_DECRYPT ( void ) noexcept
    {

        for
        (

            int SE_ITERATOR = { } ; \
            SE_ITERATOR < sizeof ... ( SE_INDEX ) ; \
            SE_ITERATOR ++

        )

        {

            SE_DATA [ SE_ITERATOR ] = SE_DATA [ SE_ITERATOR ] ^ SE_RANDOM_BUFFER [ SE_ITERATOR ] ;

        } ;

        SE_DATA [ ( sizeof ... ( SE_INDEX ) ) ] = { } ;

        return ( ( :: std :: string ) ( SE_DATA ) ) ;

    } ;

} ;

#define XS( SE_STRING )     ( :: std :: string ( :: SE_XOR_STRING < :: SE_CONSTRUCT_INDEX_LIST < sizeof ( SE_STRING ) - 1 > :: SE_RESULT > ( SE_STRING ) . SE_DECRYPT ( ) ) )
#define XCS( SE_STRING )  ( ( :: std :: string ( :: SE_XOR_STRING < :: SE_CONSTRUCT_INDEX_LIST < sizeof ( SE_STRING ) - 1 > :: SE_RESULT > ( SE_STRING ) . SE_DECRYPT ( ) ) ) . c_str ( ) )

#define XorString           XS
#define XorCString          XCS

#define SE_ZERO             ( :: std :: atoi ( XCS ( "0" ) ) )
#define SE_ONE              ( :: std :: atoi ( XCS ( "1" ) ) )
#define SE_TWO              ( :: std :: atoi ( XCS ( "2" ) ) )
#define SE_THREE            ( :: std :: atoi ( XCS ( "3" ) ) )
#define SE_FOUR             ( :: std :: atoi ( XCS ( "4" ) ) )
#define SE_FIVE             ( :: std :: atoi ( XCS ( "5" ) ) )
#define SE_SIX              ( :: std :: atoi ( XCS ( "6" ) ) )
#define SE_SEVEN            ( :: std :: atoi ( XCS ( "7" ) ) )
#define SE_EIGHT            ( :: std :: atoi ( XCS ( "8" ) ) )
#define SE_NINE             ( :: std :: atoi ( XCS ( "9" ) ) )
