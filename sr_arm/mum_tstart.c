/****************************************************************
 *								*
 *	Copyright 2001, 2009 Fidelity Information Services, Inc	*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

int mum_tstart(void)
{
  if(1)
  {
    /* getframe(); */
    inst_flush();
  } else
  {
    trans_code();
  }
  return 0;
}