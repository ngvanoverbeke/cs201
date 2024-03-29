"use strict";
eesy.define(['jquery-private', 'utils', 'mustachejs',
    'eesy-timers', 'presentation-helper'], function ($, utils, Mustache, eesyTimers, presentationHelper) {
    return {
        show: show,
        preview: preview
    };
    function show(helpItem) {
        if ($('#systraycontainer').length) {
            if ($('#systraycontainer').data("helpitemid") == helpItem.id) {
                return;
            }
            else {
                $('#systraycontainer').remove();
            }
        }
        if (utils.cookieExists("eesysystrayhidden_" + helpItem.id + "_" + var_key))
            return;
        $("body").append(Mustache.to_html(templates.systray, presentationHelper.helpItemModel(helpItem), templates));
        positionSystray(helpItem);
        $("#systraycontainer").fadeIn('slow');
    }
    function positionSystray(helpItem) {
        if (!($('#systraycontainer').length))
            return;
        if ($('#systraycontainer').data("helpitemid") != helpItem.id)
            return;
        var bottomPos = var_tab_version == 2 ? 88 : 20; // Adjust bottom if tab v2
        if (attemptUnobscure) {
            var traypos_1 = {
                left: ($("body").width() - 20) - helpItem.width,
                right: $("body").width() - 20,
                top: ($(window).height() - 20) - helpItem.height,
                bottom: $(window).height() - bottomPos
            };
            do {
                var obscuringStuff = false;
                $('input').each(function () {
                    if (utils.intersectRect(traypos_1, utils.rectangleOf($(this)))) {
                        obscuringStuff = true;
                        // nudge left
                        traypos_1.left -= 50;
                        traypos_1.right -= 50;
                    }
                });
            } while (obscuringStuff && traypos_1.right > 0);
            $('#systraycontainer').css({
                'position': 'fixed',
                'height': (traypos_1.bottom - traypos_1.top) + 'px',
                'width': (traypos_1.right - traypos_1.left) + 'px',
                'top': traypos_1.top,
                'left': traypos_1.left
            });
        }
        else {
            $('#systraycontainer').css({
                'position': 'fixed',
                'height': helpItem.height + 'px',
                'width': helpItem.width + 'px',
                'bottom': bottomPos + 'px',
                'right': '20px'
            });
        }
        eesyTimers.set("helpitem" + helpItem.id, 1000, function () {
            positionSystray(helpItem);
        });
    }
    function preview(helpItem) {
        $('#systraycontainer').remove();
        $("body").append(Mustache.to_html(templates.systray, presentationHelper.helpItemModel(helpItem), templates));
        $('#systraycontainer').css({
            'position': 'fixed',
            'height': helpItem.height + 'px',
            'width': helpItem.width + 'px',
            'bottom': '22px',
            'right': '440px'
        });
        $("#systraycontainer").show();
    }
});
//# sourceMappingURL=systrays.js.map