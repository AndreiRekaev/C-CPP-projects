#!/bin/bash

TELEGRAM_API_TOKEN="7183044720:AAGNbVBMEQqtBijJbHYdy_Ge2iHHIcK8F3g"
CHAT_ID="966516538"

URL="https://api.telegram.org/bot$TELEGRAM_API_TOKEN/sendMessage"
TEXT="Deploy status: $1%0AProject name: $CI_PROJECT_NAME%0AURL: $CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/"

curl -s -d "chat_id=$CHAT_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null