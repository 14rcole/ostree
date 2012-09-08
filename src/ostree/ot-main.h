/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2011 Colin Walters <walters@verbum.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Colin Walters <walters@verbum.org>
 */

#include <gio/gio.h>

typedef enum {
  OSTREE_BUILTIN_FLAG_NONE = 0,
  OSTREE_BUILTIN_FLAG_NO_REPO = 1,
} OstreeBuiltinFlags;

typedef struct {
  const char *name;
  gboolean (*fn) (int argc, char **argv, GFile *repo_path, GError **error);
  int flags; /* OstreeBuiltinFlags */
} OstreeCommand;

void
ostree_prep_builtin_argv (const char  *builtin,
                          int          argc,
                          char       **argv,
                          int         *out_argc,
                          char      ***out_argv);

int ostree_main (int    argc, char **argv, OstreeCommand  *commands);

int ostree_run (int argc, char **argv, OstreeCommand *commands, GError **error);

int ostree_usage (char **argv, OstreeCommand *commands, gboolean is_error);
