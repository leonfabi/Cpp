./account | awk -F ' ' '{print $2}' > new_log.txt
cat ./19920104_091532.log | awk -F ' ' '{print $2}' > new_ref.txt
diff new_log.txt new_ref.txt