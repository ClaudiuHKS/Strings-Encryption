
#pragma once

#include < string >
#include < vector >
#include < random >
#include < limits >
#include < numbers >
#include < array >
#include < bitset >

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

#define SE_UNI( MB )        ( :: toUnicode ( XCS ( MB ) ) )
#define SE_UNICODE( MB )    ( :: toUnicode ( XCS ( MB ) ) )
#define SE_WCHAR( MB )      ( :: toUnicode ( XCS ( MB ) ) )
#define SE_WIDECHAR( MB )   ( :: toUnicode ( XCS ( MB ) ) )

#define SE_UNI_C( MB )      ( :: toUnicode ( XCS ( MB ) ) . c_str ( ) )
#define SE_UNICODE_C( MB )  ( :: toUnicode ( XCS ( MB ) ) . c_str ( ) )
#define SE_WCHAR_C( MB )    ( :: toUnicode ( XCS ( MB ) ) . c_str ( ) )
#define SE_WIDECHAR_C( MB ) ( :: toUnicode ( XCS ( MB ) ) . c_str ( ) )

#define SE_ZERO             ( ( int ) ( :: std :: atof ( XCS ( "0.00000" ) ) ) )
#define SE_ONE              ( ( int ) ( :: std :: atof ( XCS ( "1.00000" ) ) ) )
#define SE_TWO              ( ( int ) ( :: std :: atof ( XCS ( "2.00000" ) ) ) )
#define SE_THREE            ( ( int ) ( :: std :: atof ( XCS ( "3.00000" ) ) ) )
#define SE_FOUR             ( ( int ) ( :: std :: atof ( XCS ( "4.00000" ) ) ) )
#define SE_FIVE             ( ( int ) ( :: std :: atof ( XCS ( "5.00000" ) ) ) )
#define SE_SIX              ( ( int ) ( :: std :: atof ( XCS ( "6.00000" ) ) ) )
#define SE_SEVEN            ( ( int ) ( :: std :: atof ( XCS ( "7.00000" ) ) ) )
#define SE_EIGHT            ( ( int ) ( :: std :: atof ( XCS ( "8.00000" ) ) ) )
#define SE_NINE             ( ( int ) ( :: std :: atof ( XCS ( "9.00000" ) ) ) )
#define SE_TEN              ( ( int ) ( :: std :: atof ( XCS ( "10.00000" ) ) ) )
#define SE_ELEVEN           ( ( int ) ( :: std :: atof ( XCS ( "11.00000" ) ) ) )
#define SE_TWELVE           ( ( int ) ( :: std :: atof ( XCS ( "12.00000" ) ) ) )
#define SE_THIRTEEN         ( ( int ) ( :: std :: atof ( XCS ( "13.00000" ) ) ) )
#define SE_FOURTEEN         ( ( int ) ( :: std :: atof ( XCS ( "14.00000" ) ) ) )
#define SE_FIVETEEN         ( ( int ) ( :: std :: atof ( XCS ( "15.00000" ) ) ) )
#define SE_SIXTEEN          ( ( int ) ( :: std :: atof ( XCS ( "16.00000" ) ) ) )
#define SE_SEVENTEEN        ( ( int ) ( :: std :: atof ( XCS ( "17.00000" ) ) ) )
#define SE_EIGHTEEN         ( ( int ) ( :: std :: atof ( XCS ( "18.00000" ) ) ) )
#define SE_NINETEEN         ( ( int ) ( :: std :: atof ( XCS ( "19.00000" ) ) ) )
#define SE_TWENTY           ( ( int ) ( :: std :: atof ( XCS ( "20.00000" ) ) ) )
#define SE_TWENTYONE        ( ( int ) ( :: std :: atof ( XCS ( "21.00000" ) ) ) )
#define SE_TWENTYTWO        ( ( int ) ( :: std :: atof ( XCS ( "22.00000" ) ) ) )
#define SE_TWENTYTHREE      ( ( int ) ( :: std :: atof ( XCS ( "23.00000" ) ) ) )
#define SE_TWENTYFOUR       ( ( int ) ( :: std :: atof ( XCS ( "24.00000" ) ) ) )
#define SE_TWENTYFIVE       ( ( int ) ( :: std :: atof ( XCS ( "25.00000" ) ) ) )
#define SE_TWENTYSIX        ( ( int ) ( :: std :: atof ( XCS ( "26.00000" ) ) ) )
#define SE_TWENTYSEVEN      ( ( int ) ( :: std :: atof ( XCS ( "27.00000" ) ) ) )
#define SE_TWENTYEIGHT      ( ( int ) ( :: std :: atof ( XCS ( "28.00000" ) ) ) )
#define SE_TWENTYNINE       ( ( int ) ( :: std :: atof ( XCS ( "29.00000" ) ) ) )
#define SE_THIRTY           ( ( int ) ( :: std :: atof ( XCS ( "30.00000" ) ) ) )
#define SE_THIRTYONE        ( ( int ) ( :: std :: atof ( XCS ( "31.00000" ) ) ) )
#define SE_THIRTYTWO        ( ( int ) ( :: std :: atof ( XCS ( "32.00000" ) ) ) )
#define SE_THIRTYTHREE      ( ( int ) ( :: std :: atof ( XCS ( "33.00000" ) ) ) )
#define SE_THIRTYFOUR       ( ( int ) ( :: std :: atof ( XCS ( "34.00000" ) ) ) )
#define SE_THIRTYFIVE       ( ( int ) ( :: std :: atof ( XCS ( "35.00000" ) ) ) )
#define SE_THIRTYSIX        ( ( int ) ( :: std :: atof ( XCS ( "36.00000" ) ) ) )
#define SE_THIRTYSEVEN      ( ( int ) ( :: std :: atof ( XCS ( "37.00000" ) ) ) )
#define SE_THIRTYEIGHT      ( ( int ) ( :: std :: atof ( XCS ( "38.00000" ) ) ) )
#define SE_THIRTYNINE       ( ( int ) ( :: std :: atof ( XCS ( "39.00000" ) ) ) )
#define SE_FOURTY           ( ( int ) ( :: std :: atof ( XCS ( "40.00000" ) ) ) )

#define SE_ZERO_F           ( ( float ) ( :: std :: atof ( XCS ( "0.00000" ) ) ) )
#define SE_ONE_F            ( ( float ) ( :: std :: atof ( XCS ( "1.00000" ) ) ) )
#define SE_TWO_F            ( ( float ) ( :: std :: atof ( XCS ( "2.00000" ) ) ) )
#define SE_THREE_F          ( ( float ) ( :: std :: atof ( XCS ( "3.00000" ) ) ) )
#define SE_FOUR_F           ( ( float ) ( :: std :: atof ( XCS ( "4.00000" ) ) ) )
#define SE_FIVE_F           ( ( float ) ( :: std :: atof ( XCS ( "5.00000" ) ) ) )
#define SE_SIX_F            ( ( float ) ( :: std :: atof ( XCS ( "6.00000" ) ) ) )
#define SE_SEVEN_F          ( ( float ) ( :: std :: atof ( XCS ( "7.00000" ) ) ) )
#define SE_EIGHT_F          ( ( float ) ( :: std :: atof ( XCS ( "8.00000" ) ) ) )
#define SE_NINE_F           ( ( float ) ( :: std :: atof ( XCS ( "9.00000" ) ) ) )
#define SE_TEN_F            ( ( float ) ( :: std :: atof ( XCS ( "10.00000" ) ) ) )
#define SE_ELEVEN_F         ( ( float ) ( :: std :: atof ( XCS ( "11.00000" ) ) ) )
#define SE_TWELVE_F         ( ( float ) ( :: std :: atof ( XCS ( "12.00000" ) ) ) )
#define SE_THIRTEEN_F       ( ( float ) ( :: std :: atof ( XCS ( "13.00000" ) ) ) )
#define SE_FOURTEEN_F       ( ( float ) ( :: std :: atof ( XCS ( "14.00000" ) ) ) )
#define SE_FIVETEEN_F       ( ( float ) ( :: std :: atof ( XCS ( "15.00000" ) ) ) )
#define SE_SIXTEEN_F        ( ( float ) ( :: std :: atof ( XCS ( "16.00000" ) ) ) )
#define SE_SEVENTEEN_F      ( ( float ) ( :: std :: atof ( XCS ( "17.00000" ) ) ) )
#define SE_EIGHTEEN_F       ( ( float ) ( :: std :: atof ( XCS ( "18.00000" ) ) ) )
#define SE_NINETEEN_F       ( ( float ) ( :: std :: atof ( XCS ( "19.00000" ) ) ) )
#define SE_TWENTY_F         ( ( float ) ( :: std :: atof ( XCS ( "20.00000" ) ) ) )
#define SE_TWENTYONE_F      ( ( float ) ( :: std :: atof ( XCS ( "21.00000" ) ) ) )
#define SE_TWENTYTWO_F      ( ( float ) ( :: std :: atof ( XCS ( "22.00000" ) ) ) )
#define SE_TWENTYTHREE_F    ( ( float ) ( :: std :: atof ( XCS ( "23.00000" ) ) ) )
#define SE_TWENTYFOUR_F     ( ( float ) ( :: std :: atof ( XCS ( "24.00000" ) ) ) )
#define SE_TWENTYFIVE_F     ( ( float ) ( :: std :: atof ( XCS ( "25.00000" ) ) ) )
#define SE_TWENTYSIX_F      ( ( float ) ( :: std :: atof ( XCS ( "26.00000" ) ) ) )
#define SE_TWENTYSEVEN_F    ( ( float ) ( :: std :: atof ( XCS ( "27.00000" ) ) ) )
#define SE_TWENTYEIGHT_F    ( ( float ) ( :: std :: atof ( XCS ( "28.00000" ) ) ) )
#define SE_TWENTYNINE_F     ( ( float ) ( :: std :: atof ( XCS ( "29.00000" ) ) ) )
#define SE_THIRTY_F         ( ( float ) ( :: std :: atof ( XCS ( "30.00000" ) ) ) )
#define SE_THIRTYONE_F      ( ( float ) ( :: std :: atof ( XCS ( "31.00000" ) ) ) )
#define SE_THIRTYTWO_F      ( ( float ) ( :: std :: atof ( XCS ( "32.00000" ) ) ) )
#define SE_THIRTYTHREE_F    ( ( float ) ( :: std :: atof ( XCS ( "33.00000" ) ) ) )
#define SE_THIRTYFOUR_F     ( ( float ) ( :: std :: atof ( XCS ( "34.00000" ) ) ) )
#define SE_THIRTYFIVE_F     ( ( float ) ( :: std :: atof ( XCS ( "35.00000" ) ) ) )
#define SE_THIRTYSIX_F      ( ( float ) ( :: std :: atof ( XCS ( "36.00000" ) ) ) )
#define SE_THIRTYSEVEN_F    ( ( float ) ( :: std :: atof ( XCS ( "37.00000" ) ) ) )
#define SE_THIRTYEIGHT_F    ( ( float ) ( :: std :: atof ( XCS ( "38.00000" ) ) ) )
#define SE_THIRTYNINE_F     ( ( float ) ( :: std :: atof ( XCS ( "39.00000" ) ) ) )
#define SE_FOURTY_F         ( ( float ) ( :: std :: atof ( XCS ( "40.00000" ) ) ) )

#define SE_0                ( ( int ) ( :: std :: atof ( XCS ( "0.00000" ) ) ) )
#define SE_1                ( ( int ) ( :: std :: atof ( XCS ( "1.00000" ) ) ) )
#define SE_2                ( ( int ) ( :: std :: atof ( XCS ( "2.00000" ) ) ) )
#define SE_3                ( ( int ) ( :: std :: atof ( XCS ( "3.00000" ) ) ) )
#define SE_4                ( ( int ) ( :: std :: atof ( XCS ( "4.00000" ) ) ) )
#define SE_5                ( ( int ) ( :: std :: atof ( XCS ( "5.00000" ) ) ) )
#define SE_6                ( ( int ) ( :: std :: atof ( XCS ( "6.00000" ) ) ) )
#define SE_7                ( ( int ) ( :: std :: atof ( XCS ( "7.00000" ) ) ) )
#define SE_8                ( ( int ) ( :: std :: atof ( XCS ( "8.00000" ) ) ) )
#define SE_9                ( ( int ) ( :: std :: atof ( XCS ( "9.00000" ) ) ) )
#define SE_10               ( ( int ) ( :: std :: atof ( XCS ( "10.00000" ) ) ) )
#define SE_11               ( ( int ) ( :: std :: atof ( XCS ( "11.00000" ) ) ) )
#define SE_12               ( ( int ) ( :: std :: atof ( XCS ( "12.00000" ) ) ) )
#define SE_13               ( ( int ) ( :: std :: atof ( XCS ( "13.00000" ) ) ) )
#define SE_14               ( ( int ) ( :: std :: atof ( XCS ( "14.00000" ) ) ) )
#define SE_15               ( ( int ) ( :: std :: atof ( XCS ( "15.00000" ) ) ) )
#define SE_16               ( ( int ) ( :: std :: atof ( XCS ( "16.00000" ) ) ) )
#define SE_17               ( ( int ) ( :: std :: atof ( XCS ( "17.00000" ) ) ) )
#define SE_18               ( ( int ) ( :: std :: atof ( XCS ( "18.00000" ) ) ) )
#define SE_19               ( ( int ) ( :: std :: atof ( XCS ( "19.00000" ) ) ) )
#define SE_20               ( ( int ) ( :: std :: atof ( XCS ( "20.00000" ) ) ) )
#define SE_21               ( ( int ) ( :: std :: atof ( XCS ( "21.00000" ) ) ) )
#define SE_22               ( ( int ) ( :: std :: atof ( XCS ( "22.00000" ) ) ) )
#define SE_23               ( ( int ) ( :: std :: atof ( XCS ( "23.00000" ) ) ) )
#define SE_24               ( ( int ) ( :: std :: atof ( XCS ( "24.00000" ) ) ) )
#define SE_25               ( ( int ) ( :: std :: atof ( XCS ( "25.00000" ) ) ) )
#define SE_26               ( ( int ) ( :: std :: atof ( XCS ( "26.00000" ) ) ) )
#define SE_27               ( ( int ) ( :: std :: atof ( XCS ( "27.00000" ) ) ) )
#define SE_28               ( ( int ) ( :: std :: atof ( XCS ( "28.00000" ) ) ) )
#define SE_29               ( ( int ) ( :: std :: atof ( XCS ( "29.00000" ) ) ) )
#define SE_30               ( ( int ) ( :: std :: atof ( XCS ( "30.00000" ) ) ) )
#define SE_31               ( ( int ) ( :: std :: atof ( XCS ( "31.00000" ) ) ) )
#define SE_32               ( ( int ) ( :: std :: atof ( XCS ( "32.00000" ) ) ) )
#define SE_33               ( ( int ) ( :: std :: atof ( XCS ( "33.00000" ) ) ) )
#define SE_34               ( ( int ) ( :: std :: atof ( XCS ( "34.00000" ) ) ) )
#define SE_35               ( ( int ) ( :: std :: atof ( XCS ( "35.00000" ) ) ) )
#define SE_36               ( ( int ) ( :: std :: atof ( XCS ( "36.00000" ) ) ) )
#define SE_37               ( ( int ) ( :: std :: atof ( XCS ( "37.00000" ) ) ) )
#define SE_38               ( ( int ) ( :: std :: atof ( XCS ( "38.00000" ) ) ) )
#define SE_39               ( ( int ) ( :: std :: atof ( XCS ( "39.00000" ) ) ) )
#define SE_40               ( ( int ) ( :: std :: atof ( XCS ( "40.00000" ) ) ) )

#define SE_0_F              ( ( float ) ( :: std :: atof ( XCS ( "0.00000" ) ) ) )
#define SE_1_F              ( ( float ) ( :: std :: atof ( XCS ( "1.00000" ) ) ) )
#define SE_2_F              ( ( float ) ( :: std :: atof ( XCS ( "2.00000" ) ) ) )
#define SE_3_F              ( ( float ) ( :: std :: atof ( XCS ( "3.00000" ) ) ) )
#define SE_4_F              ( ( float ) ( :: std :: atof ( XCS ( "4.00000" ) ) ) )
#define SE_5_F              ( ( float ) ( :: std :: atof ( XCS ( "5.00000" ) ) ) )
#define SE_6_F              ( ( float ) ( :: std :: atof ( XCS ( "6.00000" ) ) ) )
#define SE_7_F              ( ( float ) ( :: std :: atof ( XCS ( "7.00000" ) ) ) )
#define SE_8_F              ( ( float ) ( :: std :: atof ( XCS ( "8.00000" ) ) ) )
#define SE_9_F              ( ( float ) ( :: std :: atof ( XCS ( "9.00000" ) ) ) )
#define SE_10_F             ( ( float ) ( :: std :: atof ( XCS ( "10.00000" ) ) ) )
#define SE_11_F             ( ( float ) ( :: std :: atof ( XCS ( "11.00000" ) ) ) )
#define SE_12_F             ( ( float ) ( :: std :: atof ( XCS ( "12.00000" ) ) ) )
#define SE_13_F             ( ( float ) ( :: std :: atof ( XCS ( "13.00000" ) ) ) )
#define SE_14_F             ( ( float ) ( :: std :: atof ( XCS ( "14.00000" ) ) ) )
#define SE_15_F             ( ( float ) ( :: std :: atof ( XCS ( "15.00000" ) ) ) )
#define SE_16_F             ( ( float ) ( :: std :: atof ( XCS ( "16.00000" ) ) ) )
#define SE_17_F             ( ( float ) ( :: std :: atof ( XCS ( "17.00000" ) ) ) )
#define SE_18_F             ( ( float ) ( :: std :: atof ( XCS ( "18.00000" ) ) ) )
#define SE_19_F             ( ( float ) ( :: std :: atof ( XCS ( "19.00000" ) ) ) )
#define SE_20_F             ( ( float ) ( :: std :: atof ( XCS ( "20.00000" ) ) ) )
#define SE_21_F             ( ( float ) ( :: std :: atof ( XCS ( "21.00000" ) ) ) )
#define SE_22_F             ( ( float ) ( :: std :: atof ( XCS ( "22.00000" ) ) ) )
#define SE_23_F             ( ( float ) ( :: std :: atof ( XCS ( "23.00000" ) ) ) )
#define SE_24_F             ( ( float ) ( :: std :: atof ( XCS ( "24.00000" ) ) ) )
#define SE_25_F             ( ( float ) ( :: std :: atof ( XCS ( "25.00000" ) ) ) )
#define SE_26_F             ( ( float ) ( :: std :: atof ( XCS ( "26.00000" ) ) ) )
#define SE_27_F             ( ( float ) ( :: std :: atof ( XCS ( "27.00000" ) ) ) )
#define SE_28_F             ( ( float ) ( :: std :: atof ( XCS ( "28.00000" ) ) ) )
#define SE_29_F             ( ( float ) ( :: std :: atof ( XCS ( "29.00000" ) ) ) )
#define SE_30_F             ( ( float ) ( :: std :: atof ( XCS ( "30.00000" ) ) ) )
#define SE_31_F             ( ( float ) ( :: std :: atof ( XCS ( "31.00000" ) ) ) )
#define SE_32_F             ( ( float ) ( :: std :: atof ( XCS ( "32.00000" ) ) ) )
#define SE_33_F             ( ( float ) ( :: std :: atof ( XCS ( "33.00000" ) ) ) )
#define SE_34_F             ( ( float ) ( :: std :: atof ( XCS ( "34.00000" ) ) ) )
#define SE_35_F             ( ( float ) ( :: std :: atof ( XCS ( "35.00000" ) ) ) )
#define SE_36_F             ( ( float ) ( :: std :: atof ( XCS ( "36.00000" ) ) ) )
#define SE_37_F             ( ( float ) ( :: std :: atof ( XCS ( "37.00000" ) ) ) )
#define SE_38_F             ( ( float ) ( :: std :: atof ( XCS ( "38.00000" ) ) ) )
#define SE_39_F             ( ( float ) ( :: std :: atof ( XCS ( "39.00000" ) ) ) )
#define SE_40_F             ( ( float ) ( :: std :: atof ( XCS ( "40.00000" ) ) ) )
