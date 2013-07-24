/*
 *
 * (C) COPYRIGHT 2012-2013 ARM Limited. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 *
 * A copy of the licence is included with the program, and can also be obtained from Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */



#undef TRACE_SYSTEM
#define TRACE_SYSTEM mali_timeline

#if !defined(_MALI_TIMELINE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _MALI_TIMELINE_H

#include <linux/tracepoint.h>

TRACE_EVENT(mali_timeline_atoms_in_flight,

	TP_PROTO(u64 ts_sec,
		u32 ts_nsec,
		int tgid,
		int count),

	TP_ARGS(ts_sec,
		ts_nsec,
		tgid,
		count),

	TP_STRUCT__entry(
			__field(u64, ts_sec)
			__field(u32, ts_nsec)
			__field(int, tgid)
			__field(int, count)
	),

	TP_fast_assign(
		__entry->ts_sec = ts_sec;
		__entry->ts_nsec = ts_nsec;
		__entry->tgid = tgid;
		__entry->count = count;
	),

	TP_printk("%i,%i.%.9i,%i,%i", CTX_SET_NR_ATOMS_IN_FLIGHT,
				(int)__entry->ts_sec,
				(int)__entry->ts_nsec,
				__entry->tgid,
				__entry->count)
);

TRACE_EVENT(mali_timeline_gpu_slot_active,

	TP_PROTO(u64 ts_sec,
		u32 ts_nsec,
		int event_type,
		int tgid,
		int js,
		int count),

	TP_ARGS(ts_sec,
		ts_nsec,
		event_type,
		tgid,
		js,
		count),

	TP_STRUCT__entry(
			__field(u64, ts_sec)
			__field(u32, ts_nsec)
			__field(int, event_type)
			__field(int, tgid)
			__field(int, js)
			__field(int, count)
	),

	TP_fast_assign(
		__entry->ts_sec = ts_sec;
		__entry->ts_nsec = ts_nsec;
		__entry->event_type = event_type;
		__entry->tgid = tgid;
		__entry->js = js;
		__entry->count = count;
	),

	TP_printk("%i,%i.%.9i,%i,%i,%i", __entry->event_type,
				(int)__entry->ts_sec,
				(int)__entry->ts_nsec,
				__entry->tgid,
				__entry->js,
				__entry->count)
);

TRACE_EVENT(mali_timeline_gpu_power_active,

	TP_PROTO(u64 ts_sec,
		u32 ts_nsec,
		int event_type,
		int active),

	TP_ARGS(ts_sec,
		ts_nsec,
		event_type,
		active),

	TP_STRUCT__entry(
			__field(u64, ts_sec)
			__field(u32, ts_nsec)
			__field(int, event_type)
			__field(int, active)
	),

	TP_fast_assign(
		__entry->ts_sec = ts_sec;
		__entry->ts_nsec = ts_nsec;
		__entry->event_type = event_type;
		__entry->active = active;
	),

	TP_printk("%i,%i.%.9i,0,%i", __entry->event_type,
	                   (int)__entry->ts_sec,
	                   (int)__entry->ts_nsec,
	                   __entry->active)

);

TRACE_EVENT(mali_timeline_slot_atom,

	TP_PROTO(u64 ts_sec,
		u32 ts_nsec,
		int event_type,
		int tgid,
		int js,
		int atom_id),

	TP_ARGS(ts_sec,
		ts_nsec,
		event_type,
		tgid,
		js,
		atom_id),

	TP_STRUCT__entry(
			__field(u64, ts_sec)
			__field(u32, ts_nsec)
			__field(int, event_type)
			__field(int, tgid)
			__field(int, js)
			__field(int, atom_id)
	),

	TP_fast_assign(
		__entry->ts_sec = ts_sec;
		__entry->ts_nsec = ts_nsec;
		__entry->event_type = event_type;
		__entry->tgid = tgid;
		__entry->js = js;
		__entry->atom_id = atom_id;
	),

	TP_printk("%i,%i.%.9i,%i,%i,%i", __entry->event_type,
				(int)__entry->ts_sec,
				(int)__entry->ts_nsec,
				__entry->tgid,
				__entry->js,
				__entry->atom_id)
);

#endif				/* _MALI_TIMELINE_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH kbase/src/common

/* This part must be outside protection */
#include <trace/define_trace.h>

