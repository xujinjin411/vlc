/*****************************************************************************
 * libdvdcss.h: DVD reading library, exported functions.
 *****************************************************************************
 * Copyright (C) 1998-2001 VideoLAN
 * $Id: dvdcss.h,v 1.3 2001/06/20 07:43:48 sam Exp $
 *
 * Authors: St�phane Borel <stef@via.ecp.fr>
 *          Samuel Hocevar <sam@zoy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/*****************************************************************************
 * The libdvdcss structure
 *****************************************************************************/
typedef struct dvdcss_s* dvdcss_handle;

/*****************************************************************************
 * Flags
 *****************************************************************************/
#define DVDCSS_NOFLAGS         0

#define DVDCSS_INIT_QUIET      (1 << 0)
#define DVDCSS_INIT_DEBUG      (1 << 1)

#define DVDCSS_READ_DECRYPT    (1 << 0)

#define DVDCSS_BLOCK_SIZE      2048

/*****************************************************************************
 * Exported prototypes
 *****************************************************************************/
extern dvdcss_handle dvdcss_open  ( char *psz_target,
                                    int i_flags );
extern int           dvdcss_close ( dvdcss_handle );
extern int           dvdcss_crack ( dvdcss_handle,
                                    int i_title,
                                    int i_block );
extern int           dvdcss_seek  ( dvdcss_handle,
                                    int i_blocks );
extern int           dvdcss_read  ( dvdcss_handle,
                                    void *p_buffer,
                                    int i_blocks,
                                    int i_flags );
extern int           dvdcss_readv ( dvdcss_handle,
                                    void *p_iovec,
                                    int i_blocks,
                                    int i_flags );
extern char *        dvdcss_error ( dvdcss_handle );

