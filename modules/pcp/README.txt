The PCP (Profile Percent Complete) module allows privileged users to tag profile fields created through
the profile module as fields needed for a users profile to be 100% complete. The module
checks these tagged fields against each user and determines, based on what a user
has successfully completed, the percentage that has been complete.

INSTALL
==============================================
1. Download and extract the PCP module into your drupal site.
2. Go to admin/build/modules and activate the "Profile Module" and "PCP Module".
3. Make sure you set up the desired profile fields in the profile module at admin/user/profile.
4. Go to admin/user/pcp and Check the profile fields you want to use for completion then save.
  - Additionally when creating profile fields in step 3 you can tag the field there as well.
5. Go to admin/build/block and place the "Profile Complete Percentage" block to your desired location.

After steps 1 - 5 of INSTALL are complete, you will see a basic block informing you
of how much your profile has been complete. All data is determined on the fly so 
should you opt to activate or deactivate fields to be required in admin/user/pcp the displayed
data will adjust when the change has been mage.

THEME
==============================================
One function in pcp.module is being used to theme the output of the profile percentage complete block.
  - function theme_pcp_profile_percent_complete($complete_data);
To override the output of the Profile Percent Complete block, copy this function and
paste it into your template.php file and rename it to:
  A) phptemplate_pcp_profile_complete($complete_data)
  B) sitename_pcp_profile_complete($complete_data)
You now have full control of the output this block will generate.

