<?php

$after_repair_value = $entity->field_after_repair_value['und'][0]['value'];
$investor_price = $entity->field_investor_price['und'][0]['value'];
$closing_costs_to_buy = $entity->field_closing_costs_to_buy['und'][0]['value'];
$rehab_projection = $entity->field_rehab_projection['und'][0]['value'];
$property_insurance = $entity->field_property_insurance['und'][0]['value'];
$utilities = $entity->field_utilities['und'][0]['value'];
$closing_costs_to_sell = $entity->field_closing_costs_to_sell['und'][0]['value'];
$realtor_commission = $entity->field_realtor_commission['und'][0]['value'];
$rental_income = $entity->field_rental_income_per_month_['und'][0]['value'];
$property_insurance_annual = $entity->field_property_insurance_per_yea['und'][0]['value'];
$estimated_taxes_annual = $entity->field_estimated_taxes_per_year_['und'][0]['value'];
$property_management = $entity->field_property_management_per_ye['und'][0]['value'];
$maintenance = $entity->field_maintenance_per_year_['und'][0]['value'];
$hoa_dues = $entity->field_hoa_dues_per_year_['und'][0]['value'];
$expense = $investor_price + $closing_costs_to_buy + $rehab_projection + $property_insurance + $utilities + $closing_costs_to_sell + $realtor_commission;
$total_projected_profit = $after_repair_value - $expense;
$one_time_expense = $investor_price + $closing_costs_to_buy + $rehab_projection + $property_insurance + $utilities;
$annual_expense = $property_insurance_annual + $estimated_taxes_annual + $property_management + $maintenance + $hoa_dues;
$twelve_months = 12;
$projected_income = $twelve_months * $rental_income - $annual_expense;
$ROI = $total_projected_profit / $expense;
$net_annual_yield = $projected_income / $one_time_expense;

//equity score
$quality_of_comparables = $entity->field_quality_of_comparables['und'][0]['value'];
$occupancy_status = $entity->field_occupancy_status['und'][0]['value'];
$level_of_rehab = $entity->field_level_of_rehab['und'][0]['value'];
$location_of_neighborhood = $entity->field_location_of_neighborhood['und'][0]['value'];
$quality_of_floor_plan = $entity->field_quality_of_floor_plan['und'][0]['value'];
$scool_rating = $entity->field_school_rating['und'][0]['value'];
$placement_of_neighborhood = $entity->field_placement_of_neighborhood['und'][0]['value'];
$deal_recommendation = $entity->field_deal_recommendation['und'][0]['value'];
$all_equity_score = $quality_of_comparables + $occupancy_status + $level_of_rehab + $location_of_neighborhood + $quality_of_floor_plan + $scool_rating + $placement_of_neighborhood; 
if ($deal_recommendation == 'Rent') {
  $equity_score = $all_equity_score - $quality_of_comparables;
}
if ($deal_recommendation == 'Flip') {
  $equity_score = $all_equity_score - $occupancy_status;
}
?>
