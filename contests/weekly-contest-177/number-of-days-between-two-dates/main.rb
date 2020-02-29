# https://leetcode.com/contest/weekly-contest-177/problems/number-of-days-between-two-dates/

# @param {String} date1
# @param {String} date2
# @return {Integer}
require 'date'
def days_between_dates(date1, date2)
    (Date.parse(date1) - Date.parse(date2)).to_i.abs
end
