/*  VERSION.H   (c) Copyright Roger Bowler, 1999-2012                */
/*      HERCULES Emulator Version definition                         */
/*                                                                   */
/*   Released under "The Q Public License Version 1"                 */
/*   (http://www.hercules-390.org/herclic.html) as modifications to  */
/*   Hercules.                                                       */

/*-------------------------------------------------------------------*/
/* Header file defining the Hercules version number.                 */
/*                                                                   */
/* NOTE: If you're looking for the place to actually change the      */
/* number, it's in configure.ac, near the top.                       */
/*-------------------------------------------------------------------*/

#ifndef _HERCULES_H_
#define _HERCULES_H_

#include "hercules.h"

#ifndef _VERSION_C_
#ifndef _HUTIL_DLL_
#define VER_DLL_IMPORT DLL_IMPORT
#else   /* _HUTIL_DLL_ */
#define VER_DLL_IMPORT extern
#endif  /* _HUTIL_DLL_ */
#else   /* _LOGGER_C_ */
#define VER_DLL_IMPORT DLL_EXPORT
#endif /* _LOGGER_C_ */

#if 0  /* pending removal of code for V1, V2, V3, & V4  */
#if !defined(VERSION)
#if defined(V1) && defined(V2) && defined(V3) && defined(V4)
#define VER V1##.##V2##.##V3##.##V4
#define VERSION QSTR(VER)
#endif
#endif

/*
  Some modules, such as dyngui, might need these values,
  since they are ALWAYS numeric whereas VERSION is not.
*/
#if defined( _MSVC_ )
  #if (!defined(V1) || !defined(V2) || !defined(V3) || !defined(V4))



    #if ( _MSC_VER >= VS2015 )
      FIXME( "VS2015 (MSVC version 19.00) uses V1-V2-V3-V4?!" )
      FIXME( "This needs confirmed/resolved!" )
    #endif



    #error "VERSION not defined properly"



  #endif
#endif
#endif  /* #if 0  ... pending removal of code for V1, V2, V3, & V4  */

/*
  The 'VERSION' string can be any value the user wants.
*/
#if !defined(VERSION)
  WARNING("No version specified")
  #define VERSION              "0.0.0.0-(unknown!)"  /* ensure a numeric unknown version  */
  #define CUSTOM_BUILD_STRING  "('VERSION' was not defined!)"
#endif

#define HDL_VERS_HERCULES VERSION
#define HDL_SIZE_HERCULES sizeof(VERSION)

VER_DLL_IMPORT void display_version       ( FILE* f, int httpfd, char* prog );
VER_DLL_IMPORT void display_build_options ( FILE* f, int httpfd );
VER_DLL_IMPORT int get_buildinfo_strings  ( const char*** pppszBldInfoStr );

#define HERCULES_COPYRIGHT \
       "(c) Copyright 1999-2015 by Roger Bowler, Jan Jaeger, and others"
#endif // _HERCULES_H_
