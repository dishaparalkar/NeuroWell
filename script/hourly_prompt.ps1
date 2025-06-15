Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName PresentationFramework

# Toast-style balloon notification
[System.Windows.Forms.NotifyIcon]$notify = New-Object System.Windows.Forms.NotifyIcon
$notify.Icon = [System.Drawing.SystemIcons]::Information
$notify.BalloonTipTitle = "NeuroWell Hourly Check-In"
$notify.BalloonTipText = "Time to log your mood, energy, and focus!"
$notify.Visible = $true
$notify.ShowBalloonTip(10000)

# Optional: Play system sound (uncomment below to enable sound)
# [System.Media.SystemSounds]::Beep.Play()

# Wait to keep the icon visible for a short time before cleanup
Start-Sleep -Seconds 15
$notify.Dispose()

# Automatically run mood_logger if you want (optional):
# Start-Process -FilePath "D:\NeuroWell\mood_logger.exe"
