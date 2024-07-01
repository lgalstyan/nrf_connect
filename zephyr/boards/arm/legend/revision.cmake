set(LEGEND_REVISIONS "25hdd" "25ssd" "35")
if (NOT DEFINED BOARD_REVISION)
  set(BOARD_REVISION "25hdd")
else()
  if (NOT BOARD_REVISION IN_LIST LEGEND_REVISIONS)
    message(FATAL_ERROR "${BOARD_REVISION} is not a valid revision for Legend. Accepted revisions: ${LEGEND_REVISIONS}")
  endif()
endif()
